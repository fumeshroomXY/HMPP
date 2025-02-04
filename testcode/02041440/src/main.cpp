double ScreenFactor::getScreenFactor()
{
    //?�曠��?���{��
    QScreen *screen = qApp->primaryScreen();
    const int baseValue = 96;     //100%??96
    qreal dpiVal = screen->logicalDotsPerInch();
    qreal ratioVal = screen->devicePixelRatio();

    //qDebug() << dpiVal << ratioVal;
    screenFactor = dpiVal * ratioVal / baseValue;
    return screenFactor;
}
