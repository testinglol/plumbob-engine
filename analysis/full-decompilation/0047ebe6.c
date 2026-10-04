
void FUN_0047ebe6(short *param_1)

{
  char cVar1;
  int iVar2;
  int iStack0000000c;
  char *pcVar3;
  
  FUN_0046fa24(0x28);
  if ((*param_1 == 0) && ((*(byte *)((int)param_1 + 5) & 4) == 0)) {
    FUN_0046f847(s_reset_006c52c0,0xffffffff);
    iVar2 = FUN_0047eda6();
    if (iVar2 == 1) {
      pcVar3 = s___background_006c52a8;
    }
    else {
      if (iVar2 != 2) goto LAB_0047ed98;
      pcVar3 = s___carry_006c52b8;
    }
  }
  else {
    iStack0000000c = 0;
    if ((*(byte *)((int)param_1 + 5) & 4) == 0) {
      pcVar3 = &DAT_006c5298;
    }
    else {
      pcVar3 = s_id_in_s_v__006c529c;
    }
    FUN_0046f847(pcVar3,0xffffffff);
    FUN_0046fa40((int)*param_1);
    FUN_0046f847(s_from_006c5290,0xffffffff);
    cVar1 = (char)param_1[2];
    if (cVar1 == '\0') {
      FUN_0046f847(s_object_006c5268,0xffffffff);
      iStack0000000c = FUN_00457ccc();
    }
    else if (cVar1 == '\x01') {
      FUN_0046f847(s_old_global_006c5270,0xffffffff);
      iStack0000000c = FUN_0059ddda();
    }
    else if (cVar1 == '\x02') {
      FUN_0046f847(s_old_person_006c527c,0xffffffff);
      iStack0000000c = FUN_0059ddcf();
    }
    else if (cVar1 == '\x03') {
      FUN_0046f847(&DAT_006c5288,0xffffffff);
      iStack0000000c = FUN_0059dde5();
    }
    else {
      FUN_0046f847(&DAT_006c107c,0xffffffff);
    }
    if ((char)param_1[3] != '\0') {
      FUN_0046f847(s_events__006c525c,0xffffffff);
      FUN_0046fa40((int)(char)param_1[3]);
    }
    if ((*(byte *)((int)param_1 + 5) >> 1 & 1) != 0) {
      FUN_0046f847(s___backwards_006c5250,0xffffffff);
    }
    iVar2 = FUN_0047eda6();
    if (iVar2 == 1) {
      pcVar3 = s___background_006c52a8;
LAB_0047ed52:
      FUN_0046f847(pcVar3,0xffffffff);
    }
    else {
      if (iVar2 == 2) {
        pcVar3 = s___carry_006c52b8;
        goto LAB_0047ed52;
      }
      if (iVar2 == 3) {
        pcVar3 = s___stop_std_carry_006c523c;
        goto LAB_0047ed52;
      }
    }
    if ((iStack0000000c == 0) ||
       (((pcVar3 = (char *)FUN_004705f2(*param_1 + 1,0xffffffff), pcVar3 != (char *)0x0 &&
         (*pcVar3 == '\0')) || (pcVar3 == (char *)0x0)))) {
      pcVar3 = &DAT_006c107c;
    }
    FUN_0046f847(s___name__006c5230,0xffffffff);
  }
  FUN_0046f847(pcVar3,0xffffffff);
LAB_0047ed98:
  FUN_0046fa24(0x29);
  return;
}

