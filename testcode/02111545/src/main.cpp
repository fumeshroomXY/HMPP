void MdiChild::updateObjectInfoInSourceFile()
{
    qDebug() << "MdiChild::updateObjectInfoInSourceFile";
    qDebug() << "-28";

    qDebug() << "curFile: " << curFile;
    if(!curFile.endsWith(".cpp")) {
        qDebug() << "-28";
        return;   //�@�ʕs��.cpp�����C?���ڒ�?
    }

    //�Q���S�Ǎ�p��
    updateTopParenthesis();
    syntaxIssueList.clear();
    classInfoHash->clear();
    QString fileName = userFriendlyCurrentFile();
    int dotIndex = fileName.lastIndexOf('.');
    if(dotIndex <= 0) {
        qDebug() << "Cannot resolve the file className";
        qDebug() << "fileName: " << fileName;
    }else{
        fileClassName = fileName.left(dotIndex);
    }
    if(fileClassName != "main") classInfoHash->insert(fileClassName, ClassInfo(fileClassName));

    QString text = document()->toPlainText(); // ?�敶�����I���L���{

    QHash<QString, QString> methodNameToCode;

    // ��?��?�\?����\�C��??���{���ە���
    foreach (const QRegExp &reg, syntaxRuleList) {
        if(reg == classPattern){
            int pos = 0;
            int i = 0;
            int start = 0;
            int end = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // �Q�����C�z�I���e
                qDebug()  << "classPattern: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;  //type���v??���ۉ���&��*�Ccap(2)
                qDebug() << "current block: " << document()->findBlock(pos).blockNumber();
                //1?���C2*&�C3?�ʖ��C4;(
                ClassInfo info(reg.cap(1));
                if(!classInfoHash->contains(reg.cap(1))) classInfoHash->insert(reg.cap(1), info);
                classes.insert(reg.cap(3), reg.cap(1));

                //?��???�I?������
                if(reg.cap(2) == "*"){   //�@�ʐ��w?�^??�ʁC�@Student* stu =
                    // 1?���C2*�C3?�ʖ��C4?���C5�Q����\
                    QRegExp regCtr = classConstructPattern1;
                    regCtr.exactMatch(text.mid(pos));  //�@�ʕC�z�����C���v?���O?�Y��?������
                    QString matchedStr = text.mid(pos, regCtr.matchedLength());
                    if(regCtr.exactMatch(matchedStr)){
                        //?���v���͎Q����\
                        //�@�ʎQ�����ԉ�I?�^���UNSPECIFIED�C��??��
                        QString paramStr = completeMethodParamType(regCtr.cap(5), pos);
                        QStringList params = onlyGetMethodParamType(paramStr);
                        qDebug() << "params: " << params;
                        qDebug() << "paramStr: " << paramStr;
                        Method classCtr(regCtr.cap(1), regCtr.cap(1), regCtr.cap(1), params, paramStr, CLASS);
                        ClassInfo& i = (*classInfoHash)[reg.cap(1)];   //�p���p�C��?
                        if(!i.methods->contains(classCtr)){
                            qDebug() << "not contains";
                            qDebug() << "method size = " << i.methods->size();
                            i.methods->append(classCtr);
                            qDebug() << "method size = " << i.methods->size();
                            qDebug() << i.methods;
                        }

                    }
                }else{   //�@�ʐ�����??�ʁC�@Student stu()
                    //1?���C2?�ʖ��C3�Q����\
                    QRegExp regCtr = classConstructPattern2;
                    regCtr.exactMatch(text.mid(pos));  //�@�ʕC�z�����C���v?���O?�Y��?������
                    QString matchedStr = text.mid(pos, regCtr.matchedLength());
                    if(regCtr.exactMatch(matchedStr)){
                        //?���v���͎Q����\
                        //�@�ʎQ�����ԉ�I?�^���UNSPECIFIED�C��??��
                        QString paramStr = completeMethodParamType(regCtr.cap(3), pos);
                        QStringList params = onlyGetMethodParamType(paramStr);
                        qDebug() << "params: " << params;
                        qDebug() << "paramStr: " << paramStr;
                        Method classCtr(regCtr.cap(1), regCtr.cap(1), regCtr.cap(1), params, paramStr, CLASS);
                        ClassInfo& i = (*classInfoHash)[reg.cap(1)];    //�p���p�C��?
                        if(!i.methods->contains(classCtr)){
                            qDebug() << "not contains";
                            qDebug() << "method size = " << i.methods->size();
                            i.methods->append(classCtr);
                            qDebug() << "method size = " << i.methods->size();
                            qDebug() << i.methods;
                        }
                    }
                }

                //�Q��??�����I?�n�a?���ʒu
                if(i < topParenthesis.size()) {
                    start = findParenthesisStartPos(topParenthesis.at(i));
                    end = findParenthesisEndPos(topParenthesis.at(i));
                }

                if(pos <= start){
                    //�S�ǓI??��
                    Variable classVar(reg.cap(3), reg.cap(1), reg.cap(1) + reg.cap(2), GLOBAL);
                    if(!globalVars->contains(classVar)) globalVars->append(classVar);
                    pos += reg.matchedLength(); // ???�Q���꘢�C�z�ʒu
                }else if(pos > start && pos < end){  //??�������C���s���S��?��
                    Variable classVar(reg.cap(3), reg.cap(1), reg.cap(1) + reg.cap(2), LOCAL);
                    tmpVars.insert(classVar, pos);
                    pos += reg.matchedLength(); // ???�Q���꘢�C�z�ʒu
                }else if(pos >= end){   //���v�Q�����꘢??����
                    if(i >= topParenthesis.size() - 1){   //??����?�����I?�C�A���S�ǓI??��
                        Variable classVar(reg.cap(3), reg.cap(1), reg.cap(1) + reg.cap(2), GLOBAL);
                        if(!globalVars->contains(classVar)) globalVars->append(classVar);
                        pos += reg.matchedLength(); // ???�Q���꘢�C�z�ʒu
                    }else{
                        i++;
                    }
                }
            }
        }

        else if(reg == classVarAssignPattern){
            int pos = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // �Q�����C�z�I���e
                //1?�I?�ᖼ�C2.->�C3��??�ʖ��C4[]�C5??�\?��
                qDebug()  << "classAssignVar: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;
                qDebug() << "current block: " << document()->findBlock(pos).blockNumber();
                if(classes.contains(reg.cap(1)) || reg.cap(1) == "this"){
                    QString expression = reg.cap(5).trimmed();
                    QString varType = getExpressionType(expression, reg.pos(5));
                    if(!basicType.contains(varType)&& varType != UNSPECIFIED) classes.insert(reg.cap(3), varType);
                    QString className;
                    if(reg.cap(1) == "this"){
                        className = fileClassName;
                        if(fileClassName == "main"){
                            qDebug() << "Cannot use this pointer in main.cpp";
                            pos += reg.matchedLength(); // ???�Q���꘢�C�z�ʒu
                            continue;
                        }
                    }else{
                        className = classes.value(reg.cap(1));
                    }
                    Variable var(reg.cap(3), className, varType, CLASS);  //type���w��, className = ?��I??�ʖ�
                    tmpVars.insert(var, pos);
                    if(!classInfoHash->contains(className)){
                        classInfoHash->insert(className, ClassInfo(className));
                    }
                    ClassInfo info = classInfoHash->value(className);
                    //��?��?�s�d?����
                    bool flag = false;  //�p��??���ۑ��ݓ����I??��
                    for(int i = 0; i < info.vars->size(); ++i){
                        if(info.vars->at(i).name == reg.cap(3)){
                            flag = true;
                            break;
                        }
                    }
                    if(flag == false) info.vars->append(var);
                }else{
                    qDebug() << "ClassUndefined: " << reg.cap(0) << "at position:" << pos;
                    QString filePath = curFile;
                    int lineNumber = document()->findBlock(pos).blockNumber();
                    ClassUndefinedSyntaxIssue curIssue(reg.cap(1), filePath, lineNumber);
                    if(!syntaxIssueList.contains(curIssue)) syntaxIssueList.append(curIssue);
                }
                pos += reg.matchedLength(); // ???�Q���꘢�C�z�ʒu
            }

            qDebug() << "classVarPattern ends.";
        }

        else if(reg == classVarPattern){
            int pos = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // �Q�����C�z�I���e
                //1?�I?�ᖼ�C2.->�C3��??�ʖ�
                qDebug()  << "classVar: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;
                qDebug() << "current block: " << document()->findBlock(pos).blockNumber();
                if(reg.cap(3) == "h" || reg.cap(3) == "cpp") {
                    pos += reg.matchedLength();
                    continue;
                }
                if(classes.contains(reg.cap(1)) || reg.cap(1) == "this"){
                    QString className;
                    if(reg.cap(1) == "this"){
                        className = fileClassName;
                        if(fileClassName == "main"){
                            qDebug() << "Cannot use this pointer in main.cpp";
                            pos += reg.matchedLength();
                            continue;
                        }
                    }else{
                        className = getExpressionType(reg.cap(1), reg.pos(1));
                    }
                    if(className == UNSPECIFIED){
                        pos += reg.matchedLength();
                        continue;
                    }
                    QString varType = getMainWindowPtr()->findClassMemberType(className, reg.cap(3));
                    if(!basicType.contains(varType) && varType != UNSPECIFIED) classes.insert(reg.cap(3), varType);
                    Variable var(reg.cap(3), className, varType, CLASS);  //type���w��, className = ?��I??�ʖ�
                    tmpVars.insert(var, pos);
                    if(!classInfoHash->contains(className)){
                        classInfoHash->insert(className, ClassInfo(className));
                    }

                    ClassInfo info = classInfoHash->value(className);
                    //��?��?�s�d?����
                    bool flag = false;  //�p��??���ۑ��ݓ����I??��
                    for(int i = 0; i < info.vars->size(); ++i){
                        if(info.vars->at(i).name == reg.cap(3)){
                            flag = true;
                            break;
                        }
                    }
                    if(flag == false) info.vars->append(var);
                }else{
                    qDebug() << "ClassUndefined: " << reg.cap(0) << "at position:" << pos;
                    QString filePath = curFile;
                    int lineNumber = document()->findBlock(pos).blockNumber();
                    ClassUndefinedSyntaxIssue curIssue(reg.cap(1), filePath, lineNumber);
                    if(!syntaxIssueList.contains(curIssue)) syntaxIssueList.append(curIssue);
                }
                pos += reg.matchedLength(); // ???�Q���꘢�C�z�ʒu
            }

            qDebug() << "classVarPattern ends.";
        }

        //��s?�`�����C����?�ߒ�?�D�I����
        else if(reg == classMethodPattern){
            int pos = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // �Q�����C�z�I���e
                //1?�I?�ʖ��C2.->�C3��?�������C4�Q����\
                qDebug()  << "classMethod: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;
                qDebug() << "current block: " << document()->findBlock(pos).blockNumber();

                if(classes.contains(reg.cap(1)) || reg.cap(1) == "this"){
                    QString className;
                    if(reg.cap(1) == "this"){
                        className = fileClassName;
                        if(fileClassName == "main"){
                            qDebug() << "Cannot use this pointer in main.cpp";
                            pos += reg.matchedLength();
                            continue;
                        }
                    }else{
                        className = classes.value(reg.cap(1));
                    }

                    QString methodName = reg.cap(3);
                    QString actual_params = reg.cap(4);

                    QString paramStr = completeMethodParamType(actual_params, pos);
                    qDebug() << "classMethod:paramStr: " << paramStr;
                    QStringList params = onlyGetMethodParamType(paramStr);
                    qDebug() << "classMethod:params: " << params;
                    QString returnType = findMethodReturnType(methodName, className, params, CLASS);
                    Method classMethod(methodName, className, returnType, params, paramStr, CLASS);


                    //��?�C�@��?��?�`���I�����v�L�݌���������?�C???�[��?��?
                    //�\�L??��v
                    //1. ?�O?�p
                    //2. ?��?�p
                    ClassInfo& i = (*classInfoHash)[className];    //�p���p�C��?
                    if(!i.methods->contains(classMethod)){
                        qDebug() << "not contains";
                        qDebug() << "method size = " << i.methods->size();
                        i.methods->append(classMethod);
                        qDebug() << "method size = " << i.methods->size();
                        qDebug() << i.methods;
                    }
                    }else{
                        qDebug() << "ClassUndefined: " << reg.cap(0) << "at position:" << pos;
                        QString filePath = curFile;
                        int lineNumber = document()->findBlock(pos).blockNumber();
                        ClassUndefinedSyntaxIssue curIssue(reg.cap(1), filePath, lineNumber);
                        qDebug() << "curIssue: " << curIssue.getName() << " " << curIssue.getDescription() << " " << curIssue.getFilePath();
                        if(!syntaxIssueList.contains(curIssue)) syntaxIssueList.append(curIssue);
                    }
                pos += reg.matchedLength(); // ???�Q���꘢�C�z�ʒu
            }
        }

        //��s?�`�����C����?�ߒ�?�D�I����
        else if(reg == classMethodEmbededCallPattern){
            int pos = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // �Q�����C�z�I���e
                //1?�I?�ʖ��C2.->�C3��?�������C4�Q����\
                qDebug()  << "classMethodEmbededCall: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;
                qDebug() << "current block: " << document()->findBlock(pos).blockNumber();

                if(classes.contains(reg.cap(1)) || reg.cap(1) == "this"){
                    QString className;
                    if(reg.cap(1) == "this"){
                        className = fileClassName;
                        if(fileClassName == "main"){
                            qDebug() << "Cannot use this pointer in main.cpp";
                            pos += reg.matchedLength();
                            continue;
                        }
                    }else{
                        className = classes.value(reg.cap(1));
                    }

                    QString methodName = reg.cap(3);
                    QString actual_params = reg.cap(4);
                    if (actual_params.endsWith(')')) {
                        actual_params.chop(1);  // Removes the last character (closing parenthesis)
                    }

                    QString paramStr = completeMethodParamType(actual_params, pos);
                    qDebug() << "classMethod:paramStr: " << paramStr;
                    QStringList params = onlyGetMethodParamType(paramStr);
                    qDebug() << "classMethod:params: " << params;
                    QString returnType = findMethodReturnType(methodName, className, params, CLASS);
                    Method classMethod(methodName, className, returnType, params, paramStr, CLASS);


                    //��?�C�@��?��?�`���I�����v�L�݌���������?�C???�[��?��?
                    //�\�L??��v
                    //1. ?�O?�p
                    //2. ?��?�p
                    ClassInfo& i = (*classInfoHash)[className];    //�p���p�C��?
                    if(!i.methods->contains(classMethod)){
                        qDebug() << "not contains";
                        qDebug() << "method size = " << i.methods->size();
                        i.methods->append(classMethod);
                        qDebug() << "method size = " << i.methods->size();
                        qDebug() << i.methods;
                    }
                    }else{
                        qDebug() << "ClassUndefined: " << reg.cap(0) << "at position:" << pos;
                        QString filePath = curFile;
                        int lineNumber = document()->findBlock(pos).blockNumber();
                        ClassUndefinedSyntaxIssue curIssue(reg.cap(1), filePath, lineNumber);
                        qDebug() << "curIssue: " << curIssue.getName() << " " << curIssue.getDescription() << " " << curIssue.getFilePath();
                        if(!syntaxIssueList.contains(curIssue)) syntaxIssueList.append(curIssue);
                    }
                pos += reg.matchedLength(); // ???�Q���꘢�C�z�ʒu
            }
        }

        else if(reg == basicVarPattern){
            int i = 0;
            int start;
            int end;

            int pos = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // �Q�����C�z�I���e
                qDebug()  << "basicVar: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;  //type���v??���ۉ���&��*�Ccap(2)
                qDebug() << "current block: " << document()->findBlock(pos).blockNumber();

                //�Q��??�����I?�n�a?���ʒu
                if(i < topParenthesis.size()) {
                    start = findParenthesisStartPos(topParenthesis.at(i));
                    end = findParenthesisEndPos(topParenthesis.at(i));
                }

                //1?�^�C2*&�C3?�ʖ��C4[]
                if(pos <= start){
                    //�S��?��
                    Variable global = Variable(reg.cap(3), "", reg.cap(1) + reg.cap(2) + reg.cap(4), GLOBAL);
                    if(!globalVars->contains(global)) globalVars->append(global);
                    pos += reg.matchedLength(); // ???�Q���꘢�C�z�ʒu
                }else if(pos > start && pos < end){  //??�������C���s���S��?��
                    Variable tmp = Variable(reg.cap(3), "", reg.cap(1) + reg.cap(2) + reg.cap(4), LOCAL);
                    tmpVars.insert(tmp, pos);
                    pos += reg.matchedLength(); // ???�Q���꘢�C�z�ʒu
                }else if(pos >= end){
                    if(i >= topParenthesis.size() - 1){
                        Variable global = Variable(reg.cap(3), "", reg.cap(1) + reg.cap(2) + reg.cap(4), GLOBAL);
                        if(!globalVars->contains(global)) globalVars->append(global);
                        pos += reg.matchedLength(); // ???�Q���꘢�C�z�ʒu
                    }else{
                        i++;
                    }
                }
            }
        }

        else if(reg == definedMethodPattern){
            int pos = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // �Q�����C�z�I���e
                qDebug()  << "definedMethods: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;  //type���v??���ۉ���&��*�Ccap(2)
                //qDebug() << "ConstMethod: " << reg.cap(1) << " " << reg.cap(2) << " " << reg.cap(3) << " " << reg.cap(4) << " " << reg.cap(5);
                int currentBlockNumber = document()->findBlock(pos).blockNumber();
                qDebug() << "current block: " << currentBlockNumber;
                QString methodCode = findMethodCodeByName(currentBlockNumber);
                if(!methodCode.isEmpty()){
                    QString methodName = reg.cap(0);
                    if (methodName.endsWith("{")) {
                        methodName.chop(1);
                        methodName = methodName.trimmed(); // Remove last character '{'
                    }
                    methodNameToCode.insert(methodName, methodCode);
                    qDebug() << "MethodNameAndCode";
                    qDebug() << "MethodName: " << methodName;
                    qDebug() << "MethodCode: " << methodCode;
                }

                //1�ԉ�?�^�C2*&�C3?���C4�������C5�Q����\
                SCOPE scope = (reg.cap(3).isEmpty() ? GLOBAL : CLASS);  //���f?��p�搥��?��C��@Class::
                //?���v�c?�����I::���{
                QString className = (reg.cap(3).isEmpty() ?  "" : reg.cap(3).left(reg.cap(3).length() - 2) );
                QStringList params = onlyGetMethodParamType(reg.cap(5));
                Method m(reg.cap(4), className, reg.cap(1) + reg.cap(2), params, reg.cap(5), scope);
                convertMethodParamToTemp(reg.cap(5), pos + reg.matchedLength());
                if(!definedMethods->contains(m)) definedMethods->append(m);
                pos += reg.matchedLength(); // ???�Q���꘢�C�z�ʒu
            }
        }

        else if(reg == classCtrMethodPattern){
            int pos = 0;
            while ((pos = reg.indexIn(text, pos)) != -1) {
                // �Q�����C�z�I���e
                //1?���C2?���C3�Q����\�C4�`�Q�C5?��??��
                qDebug()  << "classCtrMethods: " ;
                qDebug() << "Matched text:" << reg.cap(0) << "at position:" << pos;  //type���v??���ۉ���&��*�Ccap(2)
                qDebug() << "current block: " << document()->findBlock(pos).blockNumber();
                QStringList capturedTexts = reg.capturedTexts();
                qDebug() << "Captured texts:";
                for (const QString &text : capturedTexts) {
                    qDebug() << text;
                }

                QString paramStr = reg.cap(3);
                QStringList params = onlyGetMethodParamType(paramStr);
                qDebug() << "params: " << params;
                qDebug() << "paramStr: " << paramStr;
                Method classCtr(reg.cap(1), reg.cap(1), reg.cap(1), params, paramStr, CLASS);
                ClassInfo c(reg.cap(1));
                if(!classInfoHash->contains(reg.cap(1))) classInfoHash->insert(reg.cap(1), c);
                ClassInfo& i = (*classInfoHash)[reg.cap(1)];
                if(!i.methods->contains(classCtr)){
                    qDebug() << "not contains";
                    qDebug() << "method size = " << i.methods->size();
                    i.methods->append(classCtr);
                    qDebug() << "method size = " << i.methods->size();
                    qDebug() << i.methods;
                }

                int index = 0;   //?�`?�������I�`�Q�a?��??��
                QRegExp reg_param = QRegExp("([A-Za-z_][A-Za-z0-9_]*)\\(([A-Za-z_][A-Za-z0-9_]*)\\)");
                QString classVarType, classVar;
                while ((index = reg_param.indexIn(reg.cap(0), index)) != -1){
                    QString param = reg_param.cap(2);
                    classVar = reg_param.cap(1);
                    classVarType = getExpressionType(classVar);
                    if(classVarType == "var"){
                        //�Q���Q����\��??�I?�^
                        QStringList paramList = paramStr.split(",", QString::SkipEmptyParts);
                        for(QString parameter : paramList){
                            parameter = parameter.trimmed();
                            int p = parameter.indexOf(classVar);
                            if(p != -1){
                                classVarType = parameter.remove(p, classVar.length()).trimmed();
                            }
                        }
                    }else if(classVarType == "classVar" || classVarType == "classMethod" || classVarType == "method"){
                        classVarType = getExpressionType(classVar, reg_param.pos(1));
                    }else{
                        //do nothing
                    }
                    if(classVarType.isEmpty()) classVarType = UNSPECIFIED;
                    Variable var(classVar, reg.cap(1), classVarType, CLASS);  //className = ?��I??�ʖ�
                    ClassInfo info = classInfoHash->value(reg.cap(1));
                    //��?��?�s�d?����
                    if(!info.vars->contains(var)) info.vars->append(var);
                    index += reg_param.matchedLength();
                }

                pos += reg.matchedLength();

            }
        }
    }

    qDebug() << "methodNameToCode:";
    for (auto it = methodNameToCode.constBegin(); it != methodNameToCode.constEnd(); ++it) {
        qDebug() << "Key:" << it.key() << ", Value:" << it.value();
    }

    if(!methodNameToCode.isEmpty()){
        emit updateMethodNameToCode(methodNameToCode);
    }else{
        qDebug() << "Failed to set cscrToolMethodNameToCode.";
    }

    qDebug() << "arrange defined methods.";
    //�c�ߒ�?�D�I����?����?�I?��
    for(int i = 0; i < definedMethods->size(); i++){
        if(definedMethods->at(i).scope == CLASS && !definedMethods->at(i).className.isEmpty()){  //�S�ǔ�����?
            QString className = definedMethods->at(i).className;

            if(classInfoHash->contains(className)){
                ClassInfo info = classInfoHash->value(className);
                if(!info.methods->contains(definedMethods->at(i))) info.methods->append(definedMethods->at(i));
            }else{
                ClassInfo info(className);
                info.methods->append(definedMethods->at(i));
                classInfoHash->insert(className, info);
            }
        }
    }

    qDebug() << "TempVars:";

    // �� QMultiHash ??? QMap�C����?���ň�Œ�����
    QMap<int, Variable> map;
    QList<Variable> keys = tmpVars.uniqueKeys();
    foreach (const Variable &key, keys) {
        QList<int> values = tmpVars.values(key);
        foreach (int value, values) {
            map.insertMulti(value, key);
        }
    }

    // ? QMap ?�s�r��
    QMap<int, Variable>::iterator iter;
    QMap<int, Variable> sortedMap;
    for (iter = map.begin(); iter != map.end(); ++iter) {
        sortedMap.insert(iter.key(), iter.value());
    }

    // �ň�r���@�I?��
    QMap<int, Variable>::const_iterator it;
    for (it = sortedMap.constBegin(); it != sortedMap.constEnd(); ++it) {
        qDebug() << "type:" << it.value().type << " name:" << it.value().name << " pos:" << it.key();
    }

//    QMultiHash<Variable, int>::const_iterator it;
//    for (it = tmpVars.constBegin(); it != tmpVars.constEnd(); ++it) {
//        qDebug() << "type:" << it.key().type << " name:" << it.key().name << " pos:" << it.value();
//    }

    qDebug() << "Classes:";
    for (auto i = classInfoHash->constBegin(); i != classInfoHash->constEnd(); ++i) {
        qDebug() << "**************************************";
        qDebug() << i.key() << ":";
        qDebug() << "Variables:";
        ClassInfo info = i.value();
        if(info.name == "") info.name = i.key();
        for(int j = 0; j < info.vars->size(); j++){
            qDebug() << info.vars->at(j).type << " " <<
                        info.vars->at(j).className << "::" <<info.vars->at(j).name;
        }

        qDebug() << "Methods:";
        for(int j = 0; j < info.methods->size(); j++){
            qDebug() << info.methods->at(j).returnType << " "
                     << info.methods->at(j).className << "::" <<info.methods->at(j).name
                     << "(" << info.methods->at(j).paramStr << ")";
        }
    }

    qDebug() << "GlobalVar:";
    for(int i = 0; i < globalVars->size(); ++i){
        qDebug() << "type: " << globalVars->at(i).type << "name: " << globalVars->at(i).name;
    }

    qDebug() << "DefinedMethod:";
    for(int i = 0; i < definedMethods->size(); ++i){
        qDebug() << definedMethods->at(i).returnType << " " << definedMethods->at(i).className << " "
                 << definedMethods->at(i).name << "(" << definedMethods->at(i).paramStr << ")";
    }


    qDebug() << "-28";


    //�ʒm���x���X�V?����
    emit updateClassFiles(currentFile(), *classInfoHash);
    emit showSourceFileIssue(syntaxIssueList);
}