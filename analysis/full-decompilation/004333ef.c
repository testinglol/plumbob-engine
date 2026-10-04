
void __thiscall
FUN_004333ef(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
            char param_6)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  undefined1 local_44 [4];
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_2c [4];
  int local_28;
  int local_24;
  int local_20;
  undefined2 local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  char local_5;
  
  local_14 = *(int *)(param_1 + 0xf4);
  local_10 = *(int *)(param_1 + 0xf8);
  local_5 = FUN_00422665(&local_14);
  FUN_004341a6(0);
  if (param_4 != 0) {
    FUN_004341a6(0);
  }
  local_c = param_3;
  if (param_4 != 0) {
    local_c = *(undefined4 *)(param_4 + 0x110);
  }
  FUN_00434f7b();
  sVar2 = *(short *)(param_1 + 0x4c);
  local_40 = 0;
  local_3c = 0;
  local_44[0] = 0;
  iVar6 = *(int *)(param_1 + 0xf8) >> 4;
  iVar5 = *(int *)(param_1 + 0xf4) >> 4;
  FUN_00432a70(local_44,1);
  FUN_00457da4();
  sVar1 = FUN_004561a0(0x1a);
  if (sVar1 != 0) {
    iVar3 = sVar2 * 4;
    FUN_004336c1(*(undefined4 *)(param_1 + 0xdc),*(int *)(&DAT_006c2924 + iVar3) + iVar6,
                 *(int *)(&DAT_006c2948 + iVar3) + iVar5,*(undefined4 *)(param_1 + 0x110));
  }
  iVar3 = FUN_004573f9();
  bVar7 = *(short *)(*(int *)(iVar3 + 0x60) + 0x8a) == 6;
  if (bVar7) {
    FUN_00433186(iVar6,iVar5,*(undefined4 *)(param_1 + 0x110),0);
  }
  FUN_00432728(param_2,local_c,param_4,param_5);
  FUN_00432a70(local_2c,1);
  if (local_20 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined2 *)(local_20 + 0xf0);
  }
  *(undefined2 *)(param_1 + 0x4e) = uVar4;
  *(undefined2 *)(param_1 + 0x50) = local_1c;
  if (local_20 == 0) {
    FUN_00433ef5(&local_28,local_18,0);
    *(char *)(param_1 + 0xfc) = (char)(local_24 >> 4);
    *(char *)(param_1 + 0xfd) = (char)(local_28 >> 4);
    *(undefined1 *)(param_1 + 0xfe) = (undefined1)local_18;
  }
  else {
    FUN_00433ef5(local_20 + 0xf4,local_18,0);
    iVar5 = *(int *)(local_20 + 0xf8);
    *(char *)(param_1 + 0xfd) = (char)(*(int *)(local_20 + 0xf4) >> 4);
    *(char *)(param_1 + 0xfc) = (char)(iVar5 >> 4);
    *(undefined1 *)(param_1 + 0xfe) = (undefined1)local_18;
  }
  FUN_00434f7b();
  iVar5 = *(int *)(param_1 + 0xf4) >> 4;
  iVar6 = *(int *)(param_1 + 0xf8) >> 4;
  FUN_004336c1(*(undefined4 *)(param_1 + 0xdc),iVar6,iVar5,*(undefined4 *)(param_1 + 0x110));
  FUN_00457da4();
  sVar2 = FUN_004561a0(0x1a);
  if (sVar2 != 0) {
    iVar3 = *(short *)(param_1 + 0x4c) * 4;
    FUN_004336c1(*(undefined4 *)(param_1 + 0xdc),*(int *)(&DAT_006c2924 + iVar3) + iVar6,
                 *(int *)(&DAT_006c2948 + iVar3) + iVar5,*(undefined4 *)(param_1 + 0x110));
  }
  FUN_00435051();
  if (*(short *)(*(int *)(param_1 + 0x118) + 0x14) == 0) {
    FUN_00422d79(9,0,0);
  }
  if (param_4 != 0) {
    FUN_00422d79(9,0,0);
  }
  if ((local_10 != *(int *)(param_1 + 0xf8)) || (local_14 != *(int *)(param_1 + 0xf4))) {
    FUN_004403c5(param_1);
    if ((local_5 != '\0') && (param_6 != '\0')) {
      FUN_0044756e(param_1);
    }
  }
  if (bVar7) {
    FUN_00433186(iVar6,iVar5,*(undefined4 *)(param_1 + 0x110),1);
  }
  if ((*(ushort *)(param_1 + 0x9a) & 0x400) != 0) {
    FUN_0040766a(0xf2,(int)*(short *)(param_1 + 0xf0));
  }
  return;
}

