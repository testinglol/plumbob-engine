
int * __thiscall FUN_005e926a(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 *unaff_ESI;
  
  piVar1 = (int *)FUN_005e7743();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x24))(0,param_3);
  piVar1[2] = (int)piVar1;
  (**(code **)(*piVar1 + 0x60))(*unaff_ESI,unaff_ESI[1],unaff_ESI[2],unaff_ESI[3]);
  (**(code **)(*(int *)(param_1 + -0xd4) + 0x20))(piVar1);
  return piVar1;
}

