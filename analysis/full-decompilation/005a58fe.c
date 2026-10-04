
int * __fastcall FUN_005a58fe(int *param_1)

{
  int *piVar1;
  int *local_8;
  
  piVar1 = (int *)0x0;
  local_8 = param_1;
  FUN_005e76d4(&local_8,&stack0x00000004);
  if (local_8 != (int *)*param_1) {
    piVar1 = local_8 + 5;
  }
  return piVar1;
}

