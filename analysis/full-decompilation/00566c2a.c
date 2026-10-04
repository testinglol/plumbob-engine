
undefined4 FUN_00566c2a(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = _strcmp(&DAT_006c9c58,(char *)**(undefined4 **)(param_1 + 4));
  if (iVar2 == 0) {
    if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc == 2) {
      iVar2 = FUN_00635f62(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc));
      if ((-1 < iVar2) && (iVar2 < 0x13)) {
        FUN_004f1b96(iVar2,0xffffffff);
        FUN_005dac30(0x10,param_2,iVar2);
        return 1;
      }
      pcVar3 = s_house_num_must_be_between_0_and_1_006cdadc;
    }
    else {
      pcVar3 = s_Usage__load__house_num__006cdb00;
    }
  }
  else {
    iVar2 = _strcmp(s_move_lots_006cd7a4,(char *)**(undefined4 **)(param_1 + 4));
    if (iVar2 == 0) {
      if (*(char *)(param_2 + 0x11c) == '\0') {
        FUN_005666ee(3);
      }
      return 1;
    }
    iVar2 = _strcmp(&DAT_006ce210,(char *)**(undefined4 **)(param_1 + 4));
    if (iVar2 != 0) {
      iVar2 = _strcmp(s_stream_fps_006cd81c,(char *)**(undefined4 **)(param_1 + 4));
      if (iVar2 != 0) {
        return 0;
      }
      if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc != 2) {
        return 0;
      }
      FUN_00634d24(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc),&DAT_006c5518,param_2 + 0x454);
      return 1;
    }
    if (*(char *)(param_2 + 0x360) == '\0') {
      *(undefined1 *)(param_2 + 0x360) = 1;
      if (1 < (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc) {
        piVar1 = (int *)(param_2 + 0x364);
        FUN_00634d24(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc),&DAT_006c08e4,piVar1);
        if ((2 < *piVar1) || (*piVar1 < 1)) {
          *piVar1 = 1;
        }
      }
      FUN_00567c7e();
      return 1;
    }
    pcVar3 = s_Cars_are_already_on__006ce328;
  }
  FUN_005d4bbf(pcVar3);
  return 0;
}

