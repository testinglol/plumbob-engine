
void __fastcall FUN_0043b7ef(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  FUN_0043de11();
  FUN_0059d8ef();
  FUN_004024fd();
  FUN_00404c3d();
  FUN_00405433();
  piVar3 = (int *)(param_1 + 0x20);
  uVar2 = 0;
  if (*(int *)(param_1 + 0x24) - *piVar3 >> 2 != 0) {
    do {
      FUN_0043b923(*(undefined4 *)(*piVar3 + uVar2 * 4));
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(param_1 + 0x24) - *piVar3 >> 2));
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_0043e5bf(*(int *)(param_1 + 0x2c));
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  *(undefined2 *)(param_1 + 0x38) = 0;
  **(undefined1 **)(param_1 + 0x34) = 0;
  *(undefined2 *)(param_1 + 0x148) = 0;
  **(undefined1 **)(param_1 + 0x144) = 0;
  *(undefined2 *)(param_1 + 600) = 0;
  **(undefined1 **)(param_1 + 0x254) = 0;
  *(undefined2 *)(param_1 + 0x478) = 0;
  **(undefined1 **)(param_1 + 0x474) = 0;
  FUN_0052ea87(*piVar3,*(undefined4 *)(param_1 + 0x24));
  FUN_005824b6();
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 != 0) {
    thunk_FUN_0043e4af();
    FUN_006321f0(iVar1);
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x18) = 0;
  if (iVar1 != 0) {
    FUN_004a1703();
    FUN_006321f0(iVar1);
  }
  piVar3 = *(int **)(param_1 + 0x1250);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  for (; piVar3 != *(int **)(param_1 + 0x1254); piVar3 = piVar3 + 1) {
    iVar1 = *piVar3;
    if (iVar1 != 0) {
      FUN_0045614c();
      FUN_006321f0(iVar1);
    }
  }
  FUN_0052ea87(*(undefined4 *)(param_1 + 0x1250),*(undefined4 *)(param_1 + 0x1254));
  *(undefined1 *)(param_1 + 0x14) = 0;
  FUN_0040766a(0xe0,0);
  return;
}

