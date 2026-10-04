
bool FUN_0058a133(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    uVar3 = param_2[1];
    uVar1 = (**(code **)*param_2)(uVar3);
    iVar2 = FUN_00593864(0,uVar1,uVar3);
    if (iVar2 == 0) {
      uVar3 = param_3[1];
      uVar1 = (**(code **)*param_3)(uVar3);
      iVar2 = FUN_00593864(0,uVar1,uVar3);
      return iVar2 != 0;
    }
  }
  return true;
}

