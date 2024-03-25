#include <Foundation/Foundation.h>
#include <stdio.h>
#include <stdbool.h>

bool execmode = false;

void execmodeswitch() {
    execmode = !execmode;
}

uint8_t exec(char* command) {
    if(execmode) {
        NSString *launchpath = @"/bin/bash";
        NSFileManager *fileManager = [NSFileManager defaultManager];
        if([fileManager fileExistsAtPath:launchpath]==true) {
            @autoreleasepool {
                NSTask *task = [[NSTask alloc] init];
                NSArray *arguments = [NSArray arrayWithObjects:@"-c",[NSString stringWithFormat:@"%s",command],nil];
                NSPipe *pipe = [NSPipe pipe];
                NSFileHandle *file = [pipe fileHandleForReading];
                [task setArguments:arguments];
                [task setStandardOutput:pipe];
                [task setLaunchPath:launchpath];
                [task launch];
                [task waitUntilExit];
                NSData *data = [file readDataToEndOfFile];
                const char *cOutput = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] UTF8String];
                printf("%s",cOutput);
                return (uint8_t)[task terminationStatus];
            }
            return 0;
        }
    } else {
        return 55;
    }
    return 77;
}
