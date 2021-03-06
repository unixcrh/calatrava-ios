#import <Foundation/Foundation.h>

#import "JsRuntime.h"
#import "BaseUIViewController.h"


@interface TWBridgePageRegistry : NSObject<JsRtPageDelegate, JsRtTimerDelegate, JsRtUiDelegate>
{
  id<JsRuntime> jsRt;
  UINavigationController *root;
    
  NSDictionary *pageFactories;
  NSMutableDictionary *pageProxyIds;
  NSMutableDictionary *pageObjects;
  
  BaseUIViewController *currentPage;
}

@property (nonatomic, retain) id currentPage;

+ (TWBridgePageRegistry *)sharedRegistry;

- (id)attachToRuntime:(id<JsRuntime>)rt under:(UINavigationController *)newRoot;

- (id)dispatchEvent:(NSString *)event fromProxy:(NSString *)proxyId withArgs:(NSArray *)args;

- (id)displayWidget:(NSString *)name withOptions:(NSDictionary *)options;
- (void)displayDialog:(NSString *)dialogName;

- (id)registerPage:(id)page named:(NSString *)name;

- (void)alert:(NSString *)message;

- (id)invokeCallbackForWidget:(NSString *)widget withArgs:(NSArray *)arguments;

@end
