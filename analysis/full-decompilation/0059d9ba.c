
void FUN_0059d9ba(int param_1,short param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  pcVar3 = (char *)0x0;
  iVar2 = 0;
  if (*(short *)(param_1 + 0x60c) != 0) {
    iVar2 = DAT_006f7648 + 0x438;
  }
  iVar1 = FUN_00457cf0();
  if (((iVar1 != 0) &&
      (pcVar3 = (char *)FUN_004705f2(param_2 + 1,0xffffffff), pcVar3 != (char *)0x0)) &&
     (*pcVar3 == '\0')) {
    pcVar3 = (char *)0x0;
  }
  if (iVar2 == 0) {
LAB_0059da49:
    if (pcVar3 != (char *)0x0) goto LAB_0059daaf;
  }
  else {
    if (*(short *)(param_1 + 0x600) < 0x12) {
      iVar2 = iVar2 + 0xd8;
    }
    else {
      iVar2 = (*(byte *)(param_1 + 0x60e) & 1) * 0x6c + iVar2;
    }
    if (((iVar2 == 0) ||
        (pcVar3 = (char *)FUN_004705f2(param_2 + 1,0xffffffff), pcVar3 == (char *)0x0)) ||
       (*pcVar3 != '\0')) goto LAB_0059da49;
  }
  pcVar3 = (char *)FUN_004705f2(param_2 + 1,0xffffffff);
  if ((((pcVar3 != (char *)0x0) && (*pcVar3 == '\0')) || (pcVar3 == (char *)0x0)) &&
     ((pcVar3 = (char *)FUN_004705f2(param_2 + 1,0xffffffff), pcVar3 != (char *)0x0 &&
      (*pcVar3 == '\0')))) {
    pcVar3 = (char *)0x0;
  }
LAB_0059daaf:
  FUN_0059dabd(param_1,pcVar3);
  return;
}

