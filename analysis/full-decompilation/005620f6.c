
undefined4 FUN_005620f6(int param_1,int param_2)

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
    FUN_005d4bbf(pcVar2);
  }
  else {
    iVar1 = _strcmp(s_stream_fps_006cd81c,(char *)**(undefined4 **)(param_1 + 4));
    if ((iVar1 == 0) && ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc == 2)) {
      FUN_00634d24(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc),&DAT_006c5518,param_2 + 0x19c);
      return 1;
    }
  }
  return 0;
}

