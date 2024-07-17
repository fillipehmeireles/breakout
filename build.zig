const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const mode = b.standardOptimizeOption(.{});

    //const sdl2 = b.addStaticLibrary(.{
    //   .name = "sdl2",
    //  .target = target,
    // .optimize = mode,
    // });
    //sdl2.linkLibC();
    //sdl2.linkSystemLibrary("sld2");

    const exe = b.addExecutable(.{
        .name = "breakout",
        .target = target,
        .optimize = mode,
    });

    exe.linkLibC();
    exe.linkSystemLibrary("sdl2");
    exe.addCSourceFile(.{ .file = b.path("src/main.c") });
    exe.addCSourceFile(.{ .file = b.path("src/player.c") });
    exe.addCSourceFile(.{ .file = b.path("src/game_screen.c") });

    b.installArtifact(exe);
}
