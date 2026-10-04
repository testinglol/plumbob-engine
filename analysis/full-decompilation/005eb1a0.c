
undefined4 __thiscall
FUN_005eb1a0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((*(char *)((int)param_1 + 0x14e) == '\0') || (param_1[0x5c] == 0)) {
    (**(code **)(*param_1 + 0xfc))(param_2,param_3,param_4);
  }
  else {
    (**(code **)(*param_1 + 0xf4))(param_2,param_3,param_4);
  }
  if ((param_1[0x5f] != 0) && (-1 < param_1[0x35])) {
    FUN_0057a14d(s_UI_piemenu_select_006d7814);
  }
  return 1;
}

