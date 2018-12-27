#include "highlighter.h"

//! [0]
Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(QColor(255, 51, 153));//QColor(51, 204, 51));
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\brobot\\b" << "\\blink \\b" << "\\bvisual\\b"
                    << "\\borigin\\b" << "\\bgeometry\\b" << "\\bbox\\b"
                    << "\\bcylinder\\b" << "\\bmass\\b" << "\\binertia\\b"
                    << "\\bmaterial\\b" << "\\bcollision\\b" << "\\binertial\\b"
                    << "\\bjoint\\b" << "\\baxis\\b" << "\\blimit\\b"
                    << "\\borigin\\b" << "\\bparent\\b" << "\\bchild\\b"
                    << "\\blink\\b" << "\\bxml\\b" << "\\bcylinder\\b"
                    << "\\bsafety_controller\\b"   << "\\bdynamics\\b"  << "\\bcalibration\\b"
                     << "\\bcolor\\b"       /*     << "\\btypedef\\b" << "\\btypename\\b"
                    << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
                    << "\\bvoid\\b" << "\\bvolatile\\b" << "\\bbool\\b"<<"\\busing\\b"<<"\\bconstexpr\\b"
                    <<"\\bsizeof\\b"<<"\\bif\\b"<<"\\bfor\\b"<<"\\bforeach\\b"<<"\\bwhile\\b"<<"\\bdo\\b"<<"\\bcase\\b"
                    <<"\\bbreak\\b"<<"\\bcontinue\\b"<<"\\btemplate\\b"<<"\\bdelete\\b"<<"\\bnew\\b"
                    <<"\\bdefault\\b"<<"\\btry\\b"<<"\\breturn\\b"<<"\\bthrow\\b"<<"\\bcatch\\b"<<"\\bgoto\\b"<<"\\belse\\b"
                    <<"\\bextren\\b"<<"\\bthis\\b"<<"\\bswitch\\b"<<"\\binclude\\b"<<"\\bdefine\\b"*/;
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);




//! [0] //! [1]
    }

    HighlightingRule rule2;

    keywordFormat2.setForeground(QColor(92, 214, 92));
    keywordFormat2.setFontWeight(QFont::Bold);
    QStringList keywordPatterns2;
    keywordPatterns2 << "\\bname\\b" << "\\brgba\\b" << "\\brpy\\b"
                    << "\\bsize\\b" << "\\bxyz\\b" << "\\brgba\\b"
                    << "\\beffort\\b" << "\\blower\\b" << "\\bupper\\b"
                    << "\\bvelocity\\b" << "\\btype\\b" << "\\b link\\b"
                    << "\\bversion\\b" << "\\blength\\b" << "\\bradius\\b"
                    << "\\bixx\\b" << "\\bixy\\b" << "\\bixz\\b"
                    << "\\biyy\\b" << "\\biyz\\b" << "\\bizz\\b"
                    << "\\bk_velocity\\b" << "\\bk_position\\b" << "\\bsoft_lower_limit\\b"
                    << "\\bsoft_upper_limit\\b" << "\\bdamping\\b" << "\\bfriction\\b"
                    << "\\brising\\b" << "\\bfalling\\b" << "\\bvalue\\b"
                 /*    << "\\bunion\\b" << "\\bunsigned\\b" << "\\bvirtual\\b"
                    << "\\bvoid\\b" << "\\bvolatile\\b" << "\\bbool\\b"<<"\\busing\\b"<<"\\bconstexpr\\b"
                    <<"\\bsizeof\\b"<<"\\bif\\b"<<"\\bfor\\b"<<"\\bforeach\\b"<<"\\bwhile\\b"<<"\\bdo\\b"<<"\\bcase\\b"
                    <<"\\bbreak\\b"<<"\\bcontinue\\b"<<"\\btemplate\\b"<<"\\bdelete\\b"<<"\\bnew\\b"
                    <<"\\bdefault\\b"<<"\\btry\\b"<<"\\breturn\\b"<<"\\bthrow\\b"<<"\\bcatch\\b"<<"\\bgoto\\b"<<"\\belse\\b"
                    <<"\\bextren\\b"<<"\\bthis\\b"<<"\\bswitch\\b"<<"\\binclude\\b"<<"\\bdefine\\b"*/;
    foreach (const QString &pattern2, keywordPatterns2) {
        rule2.pattern = QRegularExpression(pattern2);
        rule2.format = keywordFormat2;
        highlightingRules.append(rule2);




//! [0] //! [1]
    }






//! [1]

//! [2]
    //类 规则
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::blue);
    rule.pattern = QRegularExpression("(?<=class\\s)\\w*");
    rule.format = classFormat;
    highlightingRules.append(rule);
//! [2]

//! [3]
    //注释代码 规则
    singleLineCommentFormat.setForeground(Qt::green);
    rule.pattern = QRegularExpression("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::green);
//! [3]

//! [4]
    //头文件包含规则                                                     |\".*\"
    quotationFormat.setForeground(Qt::darkYellow);
    rule.pattern = QRegularExpression("(?<=#include\\s)(<.*>)|(?<=#include)(<.*>)|(?<=#include\\s)(\".*\")|(?<=#include)(\".*\")");
    rule.format = quotationFormat;
    highlightingRules.append(rule);
//! [4]

//! [5]
    //函数 规则                                                         ("abc(\\d+)def");  \"\\d+ \\d+ \\d+\"|\"\\d.\\d+ \\d.\\d+ \\d.\\d+\"
//    functionFormat.setFontItalic(true);
    functionFormat.setForeground(QColor(255, 255, 102));
    rule.pattern = QRegularExpression("\"(.+?)\"");
    rule.format = functionFormat;
    highlightingRules.append(rule);
//! [5]

//! [6]
    commentStartExpression = QRegularExpression("/\\*");
    commentEndExpression = QRegularExpression("\\*/");
}
//! [6]

//! [7]
void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
//! [7] //! [8]
    setCurrentBlockState(0);
//! [8]

//! [9]
    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

//! [9] //! [10]
    while (startIndex >= 0) {
//! [10] //! [11]
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}
//! [11]
