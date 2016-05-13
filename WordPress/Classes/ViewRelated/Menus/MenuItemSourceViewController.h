#import <UIKit/UIKit.h>

@class Blog;
@class MenuItem;

@protocol MenuItemSourceViewControllerDelegate;

@interface MenuItemSourceViewController : UIViewController

@property (nonatomic, weak) id <MenuItemSourceViewControllerDelegate> delegate;
@property (nonatomic, strong) Blog *blog;
@property (nonatomic, strong) MenuItem *item;

/**
 Toggled which sourceView should display based on the itemType.
 */
- (void)updateSourceSelectionForItemType:(NSString *)itemType;

/**
 Inform the view to refresh if the item's name was edited outside of this view.
 */
- (void)refreshForUpdatedItemName;

@end

@protocol MenuItemSourceViewControllerDelegate <NSObject>

/**
 Changes were made to the associated MenuItem.
 */
- (void)sourceResultsViewControllerDidUpdateItem:(MenuItemSourceViewController *)sourceViewController;

/**
 User pressed the headerView to change the toggle itemType.
 */
- (void)sourceViewControllerTypeHeaderViewWasPressed:(MenuItemSourceViewController *)sourceViewController;

/**
 Helper method for updating any layout constraints for keyboard changes.
 */
- (void)sourceViewControllerDidBeginEditingWithKeyboard:(MenuItemSourceViewController *)sourceViewController;

/**
 Helper method for updating any layout constraints for keyboard changes.
 */
- (void)sourceViewControllerDidEndEditingWithKeyboard:(MenuItemSourceViewController *)sourceViewController;

@end