
void __fastcall FUN_0056d319(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (*(undefined4 **)(param_1 + 0x218) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(param_1 + 0x218))(1);
  }
  *(undefined4 *)(param_1 + 0x218) = 0;
  piVar1 = *(int **)(param_1 + 0x1a8);
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*piVar1 + 0x8c))();
    iVar3 = (**(code **)(*piVar2 + 0xac))();
    if (((iVar3 != 0) && (iVar3 = *(int *)(param_1 + 0x1a4), iVar3 != 0)) &&
       (*(int *)(iVar3 + 0x3c) == 0)) {
      FUN_005a0903(iVar3);
    }
    iVar3 = piVar1[0x3c];
    *(undefined4 *)(param_1 + 0x1a4) = 0;
    FUN_0044127f((short)iVar3);
    *(undefined4 *)(param_1 + 0x1a8) = 0;
  }
  iVar3 = *(int *)(param_1 + 0x1ac);
  if (iVar3 != 0) {
    FUN_004094f4(0);
    if (iVar3 != 0) {
      FUN_00408c4f();
      FUN_006321f0(iVar3);
    }
    *(undefined4 *)(param_1 + 0x1ac) = 0;
  }
  FUN_005dbf4d();
  return;
}

