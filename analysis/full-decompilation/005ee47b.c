
void __fastcall FUN_005ee47b(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x80);
  iVar1 = (**(code **)(**(int **)(param_1 + 0x128) + 0x58))();
  iVar1 = iVar5 - (iVar1 * 3) / 2;
  if (*(int *)(param_1 + 0x130) == *(int *)(param_1 + 300)) {
    *(undefined4 *)(param_1 + 0x174) = 0;
    *(undefined4 *)(param_1 + 0x178) = 0;
    *(undefined4 *)(param_1 + 0x17c) = 0;
    *(undefined4 *)(param_1 + 0x180) = 0;
  }
  else {
    FUN_00473496(DAT_006e5490);
    iVar3 = **(int **)(param_1 + 0x128);
    uVar2 = FUN_004096c2(*(int *)(param_1 + 0x130) - *(int *)(param_1 + 300));
    iVar3 = (**(code **)(iVar3 + 0x68))(uVar2);
    iVar4 = __ftol();
    *(int *)(param_1 + 0x174) = iVar4;
    *(int *)(param_1 + 0x17c) = iVar4 + iVar3;
    *(int *)(param_1 + 0x178) = iVar1;
    *(int *)(param_1 + 0x180) = iVar5;
  }
  if (*(int *)(param_1 + 0x50) == *(int *)(param_1 + 0x4c)) {
    *(undefined4 *)(param_1 + 0x184) = 0;
    *(undefined4 *)(param_1 + 0x188) = 0;
    *(undefined4 *)(param_1 + 0x18c) = 0;
    *(undefined4 *)(param_1 + 400) = 0;
  }
  else {
    FUN_00473496(DAT_006e5490);
    iVar3 = **(int **)(param_1 + 0x128);
    uVar2 = FUN_004096c2(*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c));
    iVar3 = (**(code **)(iVar3 + 0x68))(uVar2);
    iVar4 = __ftol();
    *(int *)(param_1 + 0x184) = iVar4;
    *(int *)(param_1 + 0x18c) = iVar4 + iVar3;
    *(int *)(param_1 + 0x188) = iVar1;
    *(int *)(param_1 + 400) = iVar5;
  }
  return;
}

