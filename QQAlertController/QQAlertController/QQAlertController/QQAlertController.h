//
//  QQAlertController.h
//  QQAlertController
//
//  Created by 王红庆 on 2017/11/15.
//  Copyright © 2017年 王红庆. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, QQAlertControllerStyle) {
    QQAlertControllerStyleActionSheet = 0, // 从底部或顶部弹出,具体从哪里弹出取决于动画类型
    QQAlertControllerStyleAlert,           // 从中间弹出
};

typedef NS_ENUM(NSInteger, QQAlertActionStyle) {
    QQAlertActionStyleDefault = 0,  // 默认样式
    QQAlertActionStyleCancel,       // 取消样式
    QQAlertActionStyleDestructive   // 红色字体样式
};

typedef NS_ENUM(NSInteger, QQAlertAnimationType) {
    QQAlertAnimationTypeDefault = 0, // 默认动画，如果是QQAlertControllerStyleActionSheet样式,默认动画等效于QQAlertAnimationTypeRaiseUp，如果是QQAlertControllerStyleAlert样式,默认动画等效于QQAlertAnimationTypeAlpha
    QQAlertAnimationTypeRaiseUp,     // 从下往上弹，一般用于actionSheet
    QQAlertAnimationTypeDropDown,    // 从上往下弹，一般用于actionSheet
    QQAlertAnimationTypeAlpha,       // 透明度从0到1，一般用于alert
    QQAlertAnimationTypeExpand,      // 发散动画，一般用于alert
    QQAlertAnimationTypeShrink       // 收缩动画，一般用于alert
};

typedef NS_ENUM(NSInteger, QQBackgroundViewAppearanceStyle) {
    QQBackgroundViewAppearanceStyleTranslucent = 0,  // 无毛玻璃效果,黑色带透明(默认是0.5透明)
    QQBackgroundViewAppearanceStyleBlurDark,
    QQBackgroundViewAppearanceStyleBlurExtraLight,
    QQBackgroundViewAppearanceStyleBlurLight,
};

@interface QQAlertAction : NSObject <NSCopying>

+ (instancetype)qq_actionWithTitle:(nullable NSString *)title style:(QQAlertActionStyle)style handler:(void (^ __nullable)(QQAlertAction *action))handler;

@property (nullable, nonatomic, readonly) NSString *title;
@property (nonatomic, readonly) QQAlertActionStyle style;

@end

@interface QQAlertController : UIViewController

/**
 *  创建控制器
 *
 *  @param title    大标题
 *  @param message  副标题
 *  @param preferredStyle  样式
 *  @param animationType   动画类型
 */
+ (instancetype)qq_alertControllerWithTitle:(nullable NSString *)title message:(nullable NSString *)message preferredStyle:(QQAlertControllerStyle)preferredStyle animationType:(QQAlertAnimationType)animationType;

/**
 *  添加action
 */
- (void)addAction:(QQAlertAction *)action;

/** action数组 */
@property (nonatomic, readonly) NSArray<QQAlertAction *> *actions;

/**
 *  添加文本输入框
 *
 * 一旦添加后就会回调一次(仅回调一次,因此可以在这个block块里面自由定制textFiled,如设置textField的属性,设置代理,添加addTarget,监听通知等); 只有present后,textField才有superView
 */
- (void)addTextFieldWithConfigurationHandler:(void (^ __nullable)(UITextField *textField))configurationHandler;

/** textField的数组 */
@property (nullable, nonatomic, readonly) NSArray<UITextField *> *textFields;

/** 样式 */
@property (nonatomic, readonly) QQAlertControllerStyle preferredStyle;
/** 动画类型 */
@property (nonatomic, readonly) QQAlertAnimationType animationType;

/** 大标题 */
@property (nullable, nonatomic, copy) NSString *title;
/** 副标题 */
@property (nullable, nonatomic, copy) NSString *message;
/** 副标题颜色 */
@property (nonatomic, strong) UIColor *messageColor;
/** 大标题字体 */
@property (nonatomic, strong) UIFont *titleFont;
/** 副标题字体 */
@property (nonatomic, strong) UIFont *messageFont;

/** actionSheet样式下,最大的顶部间距,默认为0,iPhoneX下默认44
 如果是从顶部弹出来，该属性则充当底部间距
 */
@property (nonatomic, assign) CGFloat maxTopMarginForActionSheet;

/** alert样式下,四周的最大间距,默认为52 */
@property (nonatomic, assign) CGFloat maxMarginForAlert;

/** alert样式下，圆角半径 */
@property (nonatomic, assign) CGFloat cornerRadiusForAlert;

/** alert样式下，弹窗的中心y值，为正向下偏移，为负向上偏移 */
@property (nonatomic, assign) CGFloat offsetYForAlert;

/** alert样式下,水平排列的最大个数,如果大于了这个数,则所有action将垂直排列,默认是2.
 由于水平排列的action都是排布在footerView上,所以如果自定义了footerView，该属性将失去效用
 */
@property (nonatomic, assign) NSInteger maxNumberOfActionHorizontalArrangementForAlert;

/** 是否需要对话框拥有毛玻璃,默认为YES----Dialog单词是对话框的意思 */
@property (nonatomic, assign) BOOL needDialogBlur;

/** 是否单击背景退出对话框,默认为YES */
@property (nonatomic, assign) BOOL tapBackgroundViewDismiss;

/** 设置蒙层的外观样式,可通过alpha调整透明度,如果设置了毛玻璃样式,设置alpha<1可能会有警告,警告是正常的 */
- (void)setBackgroundViewAppearanceStyle:(QQBackgroundViewAppearanceStyle)style alpha:(CGFloat)alpha;

@end

@interface QQAlertPresentationController : UIPresentationController
@end

// ================================ 动画类 ================================

@interface QQAlertAnimation : NSObject <UIViewControllerAnimatedTransitioning>

+ (instancetype)animationIsPresenting:(BOOL)presenting;

@end

NS_ASSUME_NONNULL_END
