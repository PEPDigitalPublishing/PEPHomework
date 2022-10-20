//
//  PEPHomeworkHeader.h
//  HomeworkSample
//
//  Created by 李沛倬 on 2019/7/5.
//  Copyright © 2019 PEP. All rights reserved.
//

#ifndef PEPHomeworkHeader_h
#define PEPHomeworkHeader_h

#import <Masonry/Masonry.h>

// 日志打印宏
#ifdef DEBUG
# define PHLog(content, ...) NSLog((@"[%s -> %d]: " content), __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
# define PHLog(...)
#endif


// 判断设备类型是否是iPad
#define PHIsiPad [[UIDevice currentDevice].model containsString:@"iPad"]


// MARK: - Color

#define PHNavigationBarTintColor [UIColor colorWithRed:249/255.0 green:249/255.0 blue:249/255.0 alpha:1]

#define PHNavigationBarItemTintColor [UIColor colorWithRed:137/255.0 green:137/255.0 blue:137/255.0 alpha:1]

#define PHNavigationBarTitleColor [UIColor colorWithRed:62/255.0 green:58/255.0 blue:57/255.0 alpha:1]


/// BaseURL key
static NSString * const PHBaseURLKey = @"PHBaseURLKey";


#endif /* PEPHomeworkHeader_h */
