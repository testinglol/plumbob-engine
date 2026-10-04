
undefined4 __fastcall FUN_005eeb9a(int *param_1)

{
  int *local_c;
  int *piStack_8;
  
  local_c = param_1;
  piStack_8 = param_1;
  (**(code **)(*param_1 + 0xc))(&local_c);
  if ((local_c != (int *)0x3) && (local_c != (int *)0x2)) {
    return 0;
  }
  return 1;
}

