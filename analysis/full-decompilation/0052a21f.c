
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0052a21f(int param_1)

{
  char *_Str1;
  int iVar1;
  int iVar2;
  uint uVar3;
  float10 fVar4;
  undefined4 uVar5;
  
  fVar4 = (float10)FUN_0056f31a();
  if ((float10)_DAT_0067343c < ABS(fVar4 - (float10)_DAT_00666a44)) {
    if (ABS(fVar4 - (float10)_DAT_00666a40) <= (float10)_DAT_0067343c) {
      FUN_005e46f0(0);
      uVar5 = 1;
      goto LAB_0052a280;
    }
    if (fVar4 < (float10)_DAT_00666a38) {
      FUN_005e46f0(0);
      FUN_005e46f0(0);
      FUN_005e46f0(0);
      uVar5 = 1;
      goto LAB_0052a2eb;
    }
    FUN_005e46f0(0);
    FUN_005e46f0(0);
    uVar5 = 1;
  }
  else {
    FUN_005e46f0(1);
    uVar5 = 0;
LAB_0052a280:
    FUN_005e46f0(uVar5);
    uVar5 = 0;
  }
  FUN_005e46f0(uVar5);
  uVar5 = 0;
LAB_0052a2eb:
  FUN_005e46f0(uVar5);
  _Str1 = (char *)FUN_0056f3cd();
  uVar3 = 0;
  if ((*(int *)(param_1 + 0xfc) - *(int *)(param_1 + 0xf8)) / 0xc != 0) {
    iVar2 = 0;
    do {
      iVar1 = _strcmp(_Str1,*(char **)(*(int *)(param_1 + 0xf8) + iVar2));
      FUN_005e46f0(iVar1 == 0);
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0xc;
    } while (uVar3 < (uint)((*(int *)(param_1 + 0xfc) - *(int *)(param_1 + 0xf8)) / 0xc));
  }
  if (*(int *)(param_1 + 0x110) == 0) {
    (**(code **)(**(int **)(param_1 + 0xe0) + 0x98))();
  }
  else {
    (**(code **)(**(int **)(param_1 + 0xe0) + 0x94))();
  }
  if ((uint)((*(int *)(param_1 + 0x110) + 1) * *(int *)(param_1 + 0x114)) <
      (uint)(*(int *)(param_1 + 0xf0) - *(int *)(param_1 + 0xec) >> 2)) {
    (**(code **)(**(int **)(param_1 + 0xe4) + 0x94))();
  }
  else {
    (**(code **)(**(int **)(param_1 + 0xe4) + 0x98))();
  }
  return;
}

