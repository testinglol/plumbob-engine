
void __thiscall FUN_004d5004(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((char)param_1[0x24] != '\0') {
    FUN_005d98fc(param_1[0x20]);
    (**(code **)(*param_1 + 0x18))(param_2,param_3,param_4);
  }
  return;
}

