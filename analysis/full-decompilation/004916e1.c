
void FUN_004916e1(void)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar3 = DAT_006e54d8;
  cVar1 = (*(char **)(unaff_EBP + 8))[1];
  iVar5 = **(char **)(unaff_EBP + 8) + -2;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(int *)(unaff_EBP + -0x1c) = iVar5;
  while( true ) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(char *)(unaff_EBP + 0xb) = *(char *)(unaff_EBP + -0x14) + (char)iVar5;
    do {
      cVar2 = *(char *)(unaff_EBP + 0xb);
      cVar4 = *(char *)(unaff_EBP + -0x10) + cVar1 + -2;
      *(char *)(unaff_EBP + -0x18) = cVar2;
      *(char *)(unaff_EBP + -0x17) = cVar4;
      *(undefined1 *)(unaff_EBP + -0x16) = 1;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if ((((*(int *)(iVar3 + 0x70) <= (int)cVar2) && ((int)cVar2 <= *(int *)(iVar3 + 0x74))) &&
          (*(int *)(iVar3 + 0x78) <= (int)cVar4)) && ((int)cVar4 <= *(int *)(iVar3 + 0x7c))) {
        FUN_00492be0(unaff_EBP + -0x18);
        iVar3 = DAT_006e54d8;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < 10);
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
    if (9 < *(int *)(unaff_EBP + -0x14)) break;
    iVar5 = *(int *)(unaff_EBP + -0x1c);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

