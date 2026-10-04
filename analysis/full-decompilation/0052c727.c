
void __fastcall FUN_0052c727(int *param_1)

{
  FUN_005dae65(param_1);
  if ((char)param_1[0x69] == '\0') {
    FUN_005e40ac(param_1 + 0x65);
    *(undefined1 *)(param_1 + 0x69) = 1;
  }
  else {
    FUN_005e40ac(0);
    *(undefined1 *)(param_1 + 0x69) = 0;
  }
  (**(code **)(*param_1 + 0x168))();
  FUN_005dadff(param_1,param_1[0x6a],0);
  return;
}

