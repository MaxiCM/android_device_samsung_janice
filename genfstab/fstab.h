/*
 * Copyright (C) 2014 Marcin Chojnacki marcinch7@gmail.com
 * Copyright (C) 2014 NovaFusion https://github.com/NovaFusion
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FSTAB_H
#define FSTAB_H

#define FSTAB_PATH "/fstab.samsungjanice"

const char fstab_original_a[] =
"# Android fstab file.\n"
"#<src>                                       <mnt_point>          <type>  <mnt_flags>                                           <fs_mgr_flags>\n"
"# The filesystem that contains the filesystem checker binary (typically /system) cannot\n"
"# specify MF_CHECK, and must come before any filesystems that do specify MF_CHECK\n\n"
;

//more fancy flags to f2fs system coming soon... do you know what flags should we apply to read-only f2fs filesystem?
const char fstab_system_f2fs[] = "/dev/block/mmcblk0p3                       /system              f2fs    ro                                                    wait\n";
const char fstab_system_ext4[] = "/dev/block/mmcblk0p3                       /system              ext4    ro                                                    wait\n";

const char fstab_cache_f2fs[] = "/dev/block/mmcblk0p4                       /cache              f2fs      rw,discard,nosuid,nodev,noatime,nodiratime,flush_merge,background_gc=off,inline_xattr,active_logs=2                                      wait\n";
const char fstab_cache_ext4[] = "/dev/block/mmcblk0p4                       /cache              ext4      noatime,nosuid,nodev,journal_async_commit,errors=panic                            wait,check\n";

const char fstab_original_b[] =
"/dev/block/mmcblk0p2                    /modemfs            ext4      noatime,nosuid,nodev,journal_async_commit,errors=panic                            wait,check\n"
"/dev/block/mmcblk0p7                    /efs                ext4      noatime,nosuid,nodev,journal_async_commit,errors=panic                            wait,check\n"
;

const char fstab_data_f2fs[] = "/dev/block/mmcblk0p5                    /data               f2fs      rw,discard,nosuid,nodev,noatime,nodiratime,flush_merge,background_gc=off,inline_xattr,active_logs=2                    wait,nonremovable,encryptable=/efs/metadata\n";
const char fstab_data_ext4[] = "/dev/block/mmcblk0p5                    /data               ext4      noatime,nosuid,nodev,discard,noauto_da_alloc,journal_async_commit,errors=panic    wait,check,encryptable=/efs/metadata\n";

const char fstab_original_c[] =
"/devices/sdi2/mmc_host/mmc0/mmc0        auto                auto      defaults                                                                          voldmanaged=sdcard0:8,nonremovable,noemulatedsd\n"
"/devices/sdi0/mmc_host/mmc1/mmc1        auto                auto      defaults                                                                          voldmanaged=sdcard1:auto\n"
"/dev/block/mmcblk0p15                   /boot               emmc      defaults                                                                          recoveryonly\n"
"/dev/block/zram0                        none                swap      defaults                                                                          zramsize=268435456\n"
;

#endif
