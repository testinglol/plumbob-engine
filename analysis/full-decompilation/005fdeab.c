
undefined4 __thiscall FUN_005fdeab(int param_1,undefined4 param_2,int param_3)

{
  char *pcVar1;
  
  if (param_3 == 0) {
    param_3 = *(int *)(param_1 + 0x10);
  }
  switch(param_3) {
  case 1:
    pcVar1 = s_English_006ca7e8;
    break;
  case 2:
    pcVar1 = s_English_UK_006d83ec;
    break;
  case 3:
    pcVar1 = s_French_006caf84;
    break;
  case 4:
    pcVar1 = s_German_006caf7c;
    break;
  case 5:
    pcVar1 = s_Italian_006caf74;
    break;
  case 6:
    pcVar1 = s_Spanish_006caf6c;
    break;
  case 7:
    pcVar1 = s_Dutch_006caf64;
    break;
  case 8:
    pcVar1 = s_Danish_006caf5c;
    break;
  case 9:
    pcVar1 = s_Swedish_006caf54;
    break;
  case 10:
    pcVar1 = s_Norwegian_006caf48;
    break;
  case 0xb:
    pcVar1 = s_Finnish_006caf40;
    break;
  case 0xc:
    pcVar1 = s_Hebrew_006d83e4;
    break;
  case 0xd:
    pcVar1 = s_Russian_006d83dc;
    break;
  case 0xe:
    pcVar1 = s_Portuguese_006caf34;
    break;
  case 0xf:
    pcVar1 = s_Japanese_006caf28;
    break;
  case 0x10:
    pcVar1 = s_Polish_006caf20;
    break;
  case 0x11:
    pcVar1 = s_SimplifiedChinese_006caef8;
    break;
  case 0x12:
    pcVar1 = s_TraditionalChinese_006caf0c;
    break;
  case 0x13:
    pcVar1 = &DAT_006caef0;
    break;
  default:
    FUN_005d49b7(&DAT_006de560);
    return 0;
  }
  FUN_005d49b7(pcVar1);
  return 1;
}

