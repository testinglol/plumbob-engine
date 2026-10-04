
undefined4 __thiscall FUN_005fc3d8(int *param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *unaff_retaddr;
  
  pvVar1 = operator_new((uint)*(ushort *)(param_1 + 0x3d8));
  *param_2 = pvVar1;
  uVar2 = (**(code **)(*param_1 + 0x10))(pvVar1,(short)param_1[0x3d8]);
  if (unaff_retaddr != (undefined4 *)0x0) {
    *unaff_retaddr = uVar2;
  }
  return 1;
}

