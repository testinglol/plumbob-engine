
void __thiscall FUN_00574581(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined1 local_14 [8];
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = (int *)FUN_0057451a(&local_c,param_2,param_3);
  if (*piVar1 == 0) {
    local_c = param_2;
    local_8 = param_3;
    FUN_00576538(*(int *)(param_1 + 0xe4) + 1);
    FUN_00576349(local_14,&local_c);
  }
  return;
}

