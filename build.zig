const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const mode = b.standardOptimizeOption(.{});
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
    exe.addCSourceFile(.{ .file = b.path("src/blocks.c") });
    exe.addCSourceFile(.{ .file = b.path("src/ball.c") });

    b.installArtifact(exe);
}
