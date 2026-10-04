
void __fastcall FUN_00486e21(int param_1)

{
  int iVar1;
  char cVar2;
  SHORT SVar3;
  undefined4 uVar4;
  
  if (*(int *)(DAT_006e486c + 0x40) == 0) {
    return;
  }
  GetKeyState(0x10);
  SVar3 = GetKeyState(0x11);
  if ((SVar3 < 0) && ((*(int *)(param_1 + 0x34) == 4 || (*(int *)(param_1 + 0x34) == 3)))) {
    cVar2 = '\x01';
  }
  else {
    cVar2 = '\0';
  }
  *(char *)(param_1 + 0x79) = cVar2;
  if ((*(char *)(param_1 + 0x77) != '\0') && (cVar2 != '\0')) {
    uVar4 = 6;
    goto LAB_00486eb6;
  }
  if (*(char *)(param_1 + 0x80) == '\0') {
    if (*(int *)(param_1 + 0x3c) == 0) {
      uVar4 = 10;
      goto LAB_00486eb6;
    }
    if (*(char *)(param_1 + 0x7a) != '\0') {
      uVar4 = 0x23;
      goto LAB_00486eb6;
    }
    if (*(char *)(param_1 + 0x7b) == '\0') {
      uVar4 = 0xb;
      goto LAB_00486eb6;
    }
    iVar1 = *(int *)(param_1 + 0x7c);
    if (iVar1 == 0) {
      uVar4 = 0xe;
      goto LAB_00486eb6;
    }
    if (iVar1 == 2) {
      uVar4 = 0x10;
      goto LAB_00486eb6;
    }
    if (iVar1 == 4) {
      uVar4 = 0xf;
      goto LAB_00486eb6;
    }
    if (iVar1 == 6) {
      uVar4 = 0xd;
      goto LAB_00486eb6;
    }
  }
  uVar4 = 0xc;
LAB_00486eb6:
  FUN_004d25a5(uVar4);
  return;
}

