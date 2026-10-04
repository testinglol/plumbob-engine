
void __thiscall
FUN_005eb7d2(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  
  *(undefined1 *)(param_1 + 99) = 0;
  if (param_1[0x5f] != 0) {
    FUN_0057a14d(s_UI_piemenu_appear_006d7840);
  }
  iVar1 = FUN_00492d2c();
  if (iVar1 != 0) {
    FUN_005d9912(iVar1);
  }
  FUN_005d98fc(param_1);
  (**(code **)(*param_1 + 0x260))(param_2,param_3,param_4,param_5);
  (**(code **)(*param_1 + 0x1ac))(param_1[0x35],0);
  return;
}

