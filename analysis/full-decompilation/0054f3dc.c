
void __thiscall FUN_0054f3dc(int param_1,int param_2)

{
  *(int *)(param_1 + 0x240) = param_2;
  if (param_2 == 0) {
    FUN_005e4817(s_UI_Nhood_rollover_006cdc04,s_UI_Nhood_click_006cd914,0,0);
    *(undefined4 *)(param_1 + 0x150) = 5;
  }
  else if ((param_2 == 1) || (param_2 == 2)) {
    *(undefined4 *)(param_1 + 0x150) = 1;
  }
  return;
}

