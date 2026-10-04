
undefined4 __thiscall FUN_005d3d38(int param_1,int *param_2)

{
  int *piVar1;
  
  (**(code **)(*param_2 + 4))();
  FUN_005d3e6e(&param_2);
  piVar1 = param_2 + 6;
  (**(code **)(*param_2 + 0x18))(piVar1);
  FUN_005c7280(piVar1);
  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0xfffffffe;
  param_2[5] = param_2[5] & 0xfffffffd;
  return 0;
}

