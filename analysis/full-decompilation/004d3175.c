
void __fastcall FUN_004d3175(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_005de626();
  if (*(char *)(param_1 + 0x11b) != '\0') {
    iVar4 = FUN_004d4090();
    if (iVar4 != 0) {
      piVar5 = (int *)FUN_004d4090();
      (**(code **)(*piVar5 + 0x44))();
    }
  }
  iVar4 = FUN_004cfe0d();
  if (iVar4 == 0) {
    local_14 = *(undefined4 *)(param_1 + 0x7c);
    local_10 = *(undefined4 *)(param_1 + 0x80);
    local_c = *(undefined4 *)(param_1 + 0x84);
    local_8 = *(undefined4 *)(*(int *)(DAT_006f2a08 + 0x88) + 0x80);
    FUN_005eea5e(&local_14);
    uVar1 = *(undefined4 *)(param_1 + 0x84);
    uVar2 = *(undefined4 *)(param_1 + 0x88);
    uVar3 = *(undefined4 *)(*(int *)(DAT_006f2a08 + 0x88) + 0x80);
    iVar4 = *(int *)(DAT_006e486c + 0x4c);
    *(undefined4 *)(iVar4 + 0x2b4) = *(undefined4 *)(param_1 + 0x7c);
    *(undefined4 *)(iVar4 + 0x2b8) = uVar3;
    *(undefined4 *)(iVar4 + 700) = uVar1;
    *(undefined4 *)(iVar4 + 0x2c0) = uVar2;
  }
  else {
    iVar4 = *(int *)(DAT_006e486c + 0x4c);
    *(undefined4 *)(iVar4 + 0x2a4) = *(undefined4 *)(param_1 + 0x7c);
    *(undefined4 *)(iVar4 + 0x2a8) = *(undefined4 *)(param_1 + 0x80);
    *(undefined4 *)(iVar4 + 0x2ac) = *(undefined4 *)(param_1 + 0x84);
    *(undefined4 *)(iVar4 + 0x2b0) = *(undefined4 *)(param_1 + 0x88);
    iVar4 = *(int *)(DAT_006e486c + 0x4c);
    *(undefined4 *)(iVar4 + 0x2b4) = 0;
    *(undefined4 *)(iVar4 + 0x2b8) = 0;
    *(undefined4 *)(iVar4 + 700) = 0;
    *(undefined4 *)(iVar4 + 0x2c0) = 0;
  }
  *(undefined1 *)(DAT_006fe8f4 + 0x1f8) = 1;
  return;
}

