//
// This file is part of Lyricus.
// Copyright (c) 2008-2011, Thomas Backman <serenity@exscape.org>
// This software is distributed under the terms of the MIT license. For details, see license.txt.
//

#import <Cocoa/Cocoa.h>

#import "NSString+ExscapeEdits.h"
#import "NSTextView+ExscapeFontFix.h"
#import "SitePriorities.h"
#import "LyricFetcher.h"
#import "Batch.h"
#import "LyricSearchController.h"
#import "LyricTextView.h"
#import "AboutController.h"


@interface MainController : NSObject <NSWindowDelegate, NSTextViewDelegate, NSApplicationDelegate, LyricusDragging> {
	// Main window
	IBOutlet NSWindow *mainWindow;
	IBOutlet NSTextView *lyricView;
	IBOutlet NSProgressIndicator *spinner;
	IBOutlet NSMenuItem *editModeMenuItem;
	IBOutlet NSMenuItem *revertToSavedMenuItem;
	
	// Search window
	IBOutlet NSWindow *searchWindow;
	IBOutlet NSTextField *artistField;
	IBOutlet NSTextField *titleField;
	IBOutlet NSButton *goButton;
	
	// Preferences window
	IBOutlet NSWindow *preferencesWindow;
	IBOutlet NSButton *alwaysOnTop;
	IBOutlet NSTableView *table;
	
		AboutController *aboutController;

	//
	// Instance variables
	//
	TBSongmeanings *songmeanings;
	LyricFetcher *lyricController;
	iTunesHelper *helper;
	NSString *lastTrack;
	
	NSString *displayedArtist;
	NSString *displayedTitle;
	bool lyricsDisplayed;
	bool loadingLyrics;
	bool manualSearch;
	
	Batch *batchDownloader;
    LyricSearchController *lyricSearch;
	
	BOOL documentEdited;
	BOOL trackChangedWhileInEditMode;
	
	NSNotification *currentNotification;
	NSTimer *notificationTimer;
	BOOL receivedFirstNotification;

	BOOL zoomButtonReturnToUserState;
	BOOL zoomButtonUsedFirstTime;
	
	BOOL revertToSavedMenuItemEnabled;
	NSString *savedLyricString;
	
	NSRect userStateFrame;

}
-(BOOL) documentEdited;
-(void) setDocumentEdited:(BOOL) value;

-(void)trackUpdated;

// Preferences window
-(IBAction) openPreferencesWindow:(id) sender;
-(IBAction) alwaysOnTopClicked:(id) sender;
-(IBAction) showPreferencesHelp:(id) sender;
-(IBAction) closePreferencesButton:(id) sender;

// Search window
-(IBAction) openSearchWindow:(id) sender;
-(IBAction) goButton:(id) sender;				// Search-for-lyric button
-(void) fetchAndDisplayLyrics:(BOOL) manualSearch;
-(IBAction) getFromiTunesButton:(id) sender;
-(void) updateTextFieldsFromiTunes;
-(IBAction) closeSearchWindow:(id) sender;			// Close search window

// Misc
-(void)disableEditMode;
-(IBAction)toggleEditMode:(id) sender;
-(IBAction)saveLyrics:(id) sender;
-(BOOL)saveLyricsToNamedTrack;
-(IBAction)saveDisplayedLyricsToCurrentlyPlayingTrack:(id) sender;
-(IBAction) showAboutWindow:(id) sender;
-(IBAction)openBatchDownloader:(id)sender;
-(IBAction)openFontPanel:(id)sender;
-(IBAction)openSongMeaningsPage:(id)sender;
-(void)openSongmeaningsThread:(NSArray *)data;
-(IBAction)openLyricSearch:(id)sender;

-(BOOL)dragReceivedWithTrack:(NSDictionary *)track;

@property (retain) NSNotification *currentNotification;
@property (retain) NSTimer *notificationTimer;

@end
