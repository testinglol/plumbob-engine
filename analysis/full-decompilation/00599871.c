
undefined4 FUN_00599871(undefined4 param_1,int param_2)

{
  FUN_006326ae(param_2);
  FUN_006326ae(param_2 + 4);
  FUN_006326ae(param_2 + 8);
  FUN_006326ae(param_2 + 0xc);
  FUN_006326ae(param_2 + 0x10);
  *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + 1;
  return param_1;
}

