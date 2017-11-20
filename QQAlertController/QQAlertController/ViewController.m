//
//  ViewController.m
//  QQAlertController
//
//  Created by 王红庆 on 2017/11/15.
//  Copyright © 2017年 王红庆. All rights reserved.
//

#import "ViewController.h"
#import "QQAlertController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    UIButton *button = [[UIButton alloc] init];
    [button setTitle:@"弹出 QQAlertController" forState:UIControlStateNormal];
    [button setTitleColor:[UIColor redColor] forState:UIControlStateNormal];
    [button addTarget:self action:@selector(alert:) forControlEvents:UIControlEventTouchUpInside];
    button.frame = CGRectMake(0, 330, 375, 40);
    [self.view addSubview:button];
}

- (void)alertQQTest {
    
    QQAlertController *alertController = [QQAlertController qq_alertControllerWithTitle:@"温馨提示" message:@"您的计数还未提交，是否退出？" preferredStyle:QQAlertControllerStyleAlert animationType:QQAlertAnimationTypeShrink];
//    QQAlertController *alertController = [QQAlertController qq_alertControllerWithTitle:@"温馨提示" message:@"您的计数还未提交，是否退出？" preferredStyle:QQAlertControllerStyleActionSheet animationType:QQAlertAnimationTypeShrink];
    // 默认超过2个按钮就垂直排列，想要超过2个按钮依然水平排列，修改水平排列的最大个数，只要没超过这个最大数，一律水平排列
    //    alertController.maxNumberOfActionHorizontalArrangementForAlert = 3;
    
    QQAlertAction *ok = [QQAlertAction actionWithTitle:@"退出" style:QQAlertActionStyleDefault handler:^(QQAlertAction * _Nonnull action) {
        NSLog(@"ok");
    }];
    
    // SPAlertActionStyleDestructive默认文字为红色(可修改)
    QQAlertAction *action2 = [QQAlertAction actionWithTitle:@"第2个" style:QQAlertActionStyleDestructive handler:^(QQAlertAction * _Nonnull action) {
        NSLog(@"点击了第2个");
    }];
    QQAlertAction *cancel = [QQAlertAction actionWithTitle:@"取消" style:QQAlertActionStyleCancel handler:^(QQAlertAction * _Nonnull action) {
        NSLog(@"cancel");
    }];
    
    [alertController addAction:ok];
    [alertController addAction:action2];
    [alertController addAction:cancel];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

#pragma mark - Event Response
- (void)alert:(UIButton *)button {
    
    [self alertQQTest];
    
//    [self alertSystem];
}

- (void)alertSystem {
    
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Title" message:@"message" preferredStyle:UIAlertControllerStyleAlert];

    UIAlertAction *ok = [UIAlertAction actionWithTitle:@"ok" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        NSLog(@"ok");
    }];
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        NSLog(@"cancel");
    }];
    
    UIAlertAction *delete = [UIAlertAction actionWithTitle:@"delete" style:UIAlertActionStyleDestructive handler:^(UIAlertAction * _Nonnull action) {
        NSLog(@"delete");
    }];

    [alertController addAction:ok];
    [alertController addAction:cancel];
    [alertController addAction:delete];

    [self presentViewController:alertController animated:YES completion:nil];
}

@end
