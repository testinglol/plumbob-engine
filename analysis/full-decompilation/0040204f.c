
undefined4 __thiscall FUN_0040204f(undefined4 *param_1,undefined4 param_2)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_retaddr;
  
  piVar2 = (int *)(**(code **)*param_1)(param_2);
  if ((piVar2 != (int *)0x0) &&
     (iVar3 = (**(code **)(*piVar2 + 0x38))(0x42484156,unaff_retaddr,param_1[5]), iVar3 != 0)) {
    sVar1 = FUN_004200a5(iVar3);
    if (sVar1 == 0) {
      FUN_00420048(iVar3);
    }
    uVar4 = FUN_00420048(iVar3);
    FUN_0042004f(iVar3);
    return uVar4;
  }
  return 0;
}

