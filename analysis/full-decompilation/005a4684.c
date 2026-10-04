
uint __fastcall FUN_005a4684(int param_1)

{
  char cVar1;
  int iVar2;
  uint in_EAX;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (*(int *)(param_1 + 0x234) == 0) {
LAB_005a47aa:
    uVar4 = in_EAX & 0xffffff00;
  }
  else {
    in_EAX = *(uint *)(param_1 + 0x230);
    iVar2 = *(int *)(param_1 + 0x224);
    if (*(char *)(iVar2 + in_EAX) == '\"') {
      iVar6 = *(int *)(param_1 + 0x228);
      iVar3 = in_EAX + 1;
      iVar5 = *(int *)(param_1 + 0x234) + -1;
      *(undefined4 *)(param_1 + 0x23c) = 0;
      *(int *)(param_1 + 0x230) = iVar3;
      *(int *)(param_1 + 0x234) = iVar5;
      *(int *)(param_1 + 0x238) = iVar3;
      while ((iVar3 < iVar6 && (*(char *)(iVar3 + iVar2) != '\"'))) {
        iVar3 = iVar3 + 1;
        iVar5 = iVar5 + -1;
        *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
        *(int *)(param_1 + 0x230) = iVar3;
        *(int *)(param_1 + 0x234) = iVar5;
      }
      in_EAX = *(uint *)(param_1 + 0x230);
      if (iVar6 <= (int)in_EAX) goto LAB_005a47aa;
      in_EAX = in_EAX + 1;
      *(int *)(param_1 + 0x234) = *(int *)(param_1 + 0x234) + -1;
      *(uint *)(param_1 + 0x230) = in_EAX;
      if ((int)in_EAX < iVar6) goto LAB_005a470b;
    }
    else {
      *(undefined4 *)(param_1 + 0x23c) = 0;
      iVar6 = *(int *)(param_1 + 0x228);
      *(uint *)(param_1 + 0x238) = in_EAX;
      while (((int)in_EAX < iVar6 && (0 < *(int *)(param_1 + 0x234)))) {
        in_EAX = *(uint *)(param_1 + 0x230);
        cVar1 = *(char *)(iVar2 + in_EAX);
        if ((cVar1 == '\n') || ((cVar1 == ',' || (cVar1 == '\r')))) break;
        in_EAX = in_EAX + 1;
        *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
        *(uint *)(param_1 + 0x230) = in_EAX;
        *(int *)(param_1 + 0x234) = *(int *)(param_1 + 0x234) + -1;
      }
      if (iVar6 <= *(int *)(param_1 + 0x230)) goto LAB_005a47aa;
LAB_005a470b:
      do {
        if (*(int *)(param_1 + 0x234) < 1) break;
        in_EAX = *(uint *)(param_1 + 0x230);
        cVar1 = *(char *)(iVar2 + in_EAX);
        if ((((cVar1 != ' ') && (cVar1 != '\n')) && (cVar1 != '\t')) &&
           ((cVar1 != ',' && (cVar1 != '\r')))) break;
        in_EAX = in_EAX + 1;
        *(uint *)(param_1 + 0x230) = in_EAX;
        *(int *)(param_1 + 0x234) = *(int *)(param_1 + 0x234) + -1;
      } while ((int)in_EAX < iVar6);
    }
    uVar4 = CONCAT31((int3)(in_EAX >> 8),1);
  }
  return uVar4;
}

