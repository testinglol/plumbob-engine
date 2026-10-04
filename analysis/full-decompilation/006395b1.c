
uint FUN_006395b1(byte param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  
  pcVar4 = param_2;
  if (param_2[1] == ':') {
    pcVar4 = param_2 + 2;
  }
  cVar1 = *pcVar4;
  if ((((cVar1 == '\\') || (cVar1 == '/')) && (pcVar4[1] == '\0')) ||
     (((param_1 & 0x10) != 0 || (uVar5 = 0x8000, cVar1 == '\0')))) {
    uVar5 = 0x4040;
  }
  uVar5 = uVar5 | (uint)(~param_1 & 1 | 2) << 7;
  iVar2 = FUN_006375b5(param_2,0x2e);
  if (iVar2 != 0) {
    iVar3 = FUN_0063bae1(iVar2,&DAT_00677c70);
    if (iVar3 != 0) {
      iVar3 = FUN_0063bae1(iVar2,&DAT_0068939c);
      if (iVar3 != 0) {
        iVar3 = FUN_0063bae1(iVar2,&DAT_00689394);
        if (iVar3 != 0) {
          iVar2 = FUN_0063bae1(iVar2,&DAT_0068938c);
          if (iVar2 != 0) goto LAB_00639652;
        }
      }
    }
    uVar5 = uVar5 | 0x40;
  }
LAB_00639652:
  return (uVar5 & 0x1c0) >> 6 | uVar5 | uVar5 >> 3 & 0x38;
}

