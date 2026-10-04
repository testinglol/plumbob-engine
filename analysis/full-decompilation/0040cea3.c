
void __thiscall FUN_0040cea3(int param_1,int param_2,char *param_3)

{
  char *pcVar1;
  undefined **ppuVar2;
  
  if (param_2 == 0) {
    pcVar1 = &DAT_006c1070;
    goto LAB_0040cf04;
  }
  if (param_2 == 1) {
    pcVar1 = s_female_006c1068;
    goto LAB_0040cf04;
  }
  if (param_2 == 2) {
    pcVar1 = s_dogmale_006c1060;
LAB_0040ceec:
    ppuVar2 = &PTR_PTR_006c0fa4;
  }
  else {
    if (param_2 == 3) {
      pcVar1 = s_dogfemale_006c1054;
      goto LAB_0040ceec;
    }
    if (param_2 == 4) {
      pcVar1 = s_catmale_006c104c;
    }
    else {
      pcVar1 = param_3;
      if (param_2 != 5) goto LAB_0040cf04;
      pcVar1 = s_catfemale_006c1040;
    }
    ppuVar2 = (undefined **)&DAT_006c1078;
  }
  FUN_005876ac(1,ppuVar2);
LAB_0040cf04:
  FUN_005876ac(0xd,pcVar1);
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  if ((char)param_3 != '\0') {
    FUN_0040a5ea();
  }
  return;
}

