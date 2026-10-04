
undefined4 FUN_0054ca00(int param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = _strcmp(&DAT_006c9c58,(char *)**(undefined4 **)(param_1 + 4));
  if (iVar1 == 0) {
    if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc == 2) {
      iVar1 = FUN_00635f62(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc));
      if ((-1 < iVar1) && (iVar1 < 0x13)) {
        FUN_004f1b96(iVar1,0xffffffff);
        FUN_005dac30(0x10,param_2,iVar1);
        return 1;
      }
      pcVar2 = s_house_num_must_be_between_0_and_1_006cdadc;
    }
    else {
      pcVar2 = s_Usage__load__house_num__006cdb00;
    }
  }
  else {
    iVar1 = _strcmp(s_move_lots_006cd7a4,(char *)**(undefined4 **)(param_1 + 4));
    if (iVar1 == 0) {
      if (*(char *)(param_2 + 0x110) == '\0') {
        FUN_0054c4af(3);
      }
      return 1;
    }
    iVar1 = _strcmp(s_nessie_006cd7f4,(char *)**(undefined4 **)(param_1 + 4));
    if (iVar1 != 0) {
      iVar1 = _strcmp(s_stream_fps_006cd81c,(char *)**(undefined4 **)(param_1 + 4));
      if (iVar1 != 0) {
        return 0;
      }
      if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 2) {
        return 0;
      }
      FUN_00634d24(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc),&DAT_006c5518,param_2 + 0x1e4);
      return 1;
    }
    if (*(char *)(param_2 + 0x111) == '\0') {
      *(undefined4 *)(param_2 + 0x11c) = 0xffffffff;
      *(undefined4 *)(param_2 + 0x124) = 0xffffffff;
      *(undefined1 *)(param_2 + 0x111) = 1;
      *(undefined4 *)(param_2 + 0x114) = 0x213;
      *(undefined4 *)(param_2 + 0x118) = 0x1b6;
      return 1;
    }
    pcVar2 = s_Sorry_only_one_Nessie_at_a_time__006cdab8;
  }
  FUN_005d4bbf(pcVar2);
  return 0;
}

