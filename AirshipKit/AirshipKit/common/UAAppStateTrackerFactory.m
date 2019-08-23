/* Copyright Airship and Contributors */

#import "UAAppStateTrackerFactory.h"
#import "UAUIKitStateTracker+Internal.h"

@implementation UAAppStateTrackerFactory

+ (id<UAAppStateTracker>)tracker {
    return [UAUIKitStateTracker trackerWithApplication:[UIApplication sharedApplication]
                                    notificationCenter:[NSNotificationCenter defaultCenter]];
}

@end
