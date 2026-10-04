
undefined4 __thiscall FUN_005fdd44(int param_1,undefined4 param_2,int param_3)

{
  char *pcVar1;
  
  if (param_3 == 0) {
    param_3 = *(int *)(param_1 + 0x10);
  }
  switch(param_3 + -1) {
  case 0:
  case 0xb:
    pcVar1 = s_english_006d83d4;
    break;
  case 1:
    pcVar1 = s_english_uk_006d83c8;
    break;
  case 2:
    pcVar1 = s_french_006d83c0;
    break;
  case 3:
    pcVar1 = s_german_006d83b8;
    break;
  case 4:
    pcVar1 = s_italian_006d83b0;
    break;
  case 5:
    pcVar1 = s_spanish_006d83a8;
    break;
  case 6:
    pcVar1 = s_dutch_006d8374;
    break;
  case 7:
    pcVar1 = s_danish_006d83a0;
    break;
  case 8:
    pcVar1 = s_swedish_006d8398;
    break;
  case 9:
    pcVar1 = s_norwegian_006d8368;
    break;
  case 10:
    pcVar1 = s_finnish_006d8360;
    break;
  case 0xc:
    pcVar1 = s_russian_006d8390;
    break;
  case 0xd:
    pcVar1 = s_portuguese_006d8354;
    break;
  case 0xe:
    pcVar1 = s_japanese_006d837c;
    break;
  case 0xf:
    pcVar1 = s_polish_006d8388;
    break;
  case 0x10:
    pcVar1 = s_chinese_simplified_006d8340;
    break;
  case 0x11:
    pcVar1 = s_chinese_traditional_006d832c;
    break;
  case 0x12:
    pcVar1 = (char *)0x6d8324;
    break;
  case 0x13:
    pcVar1 = s_korean_006d831c;
    break;
  default:
    return 0;
  }
  FUN_005d49b7(pcVar1);
  return 1;
}

