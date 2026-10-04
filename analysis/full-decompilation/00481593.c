
char FUN_00481593(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  undefined4 uVar6;
  uint uVar7;
  char cVar8;
  int extraout_ECX;
  char cVar9;
  int unaff_EBP;
  int iVar10;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  uVar6 = FUN_00433116(piVar1,1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar5 = FUN_00433136(uVar6);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (cVar5 != '\0') {
LAB_004816f5:
    cVar5 = '\0';
    goto LAB_0048173a;
  }
  iVar10 = extraout_ECX;
  if ((*(byte *)(extraout_ECX + 0x29) & 8) == 0) {
    iVar10 = *(int *)(extraout_ECX + 0x4c);
    iVar2 = *piVar1;
    uVar6 = *(undefined4 *)(iVar10 + 0x110);
    cVar5 = (char)(piVar1[1] >> 4);
    *(char *)(unaff_EBP + 8) = cVar5;
    cVar8 = (char)(iVar2 >> 4);
    *(char *)(unaff_EBP + 9) = cVar8;
    cVar9 = (char)uVar6;
    *(char *)(unaff_EBP + 10) = cVar9;
    iVar2 = DAT_006e54dc;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (*(short *)(*(int *)(*(int *)(*(int *)(iVar2 + 0x28 + cVar9 * 4) + 0xc) + cVar5 * 4) +
                  cVar8 * 2) != *(short *)(iVar10 + 0x84)) {
      cVar5 = '\x02';
      goto LAB_0048173a;
    }
    uVar3 = *(uint *)(unaff_EBP + 0xc);
    if ((uVar3 == 0xffffffff) ||
       ((uVar7 = FUN_00435a8f(unaff_EBP + 8,uVar3 - 4 & 7), (uVar7 & 1) == 0 &&
        (((uVar3 & 1) == 0 || ((uVar7 & 0x82) == 0)))))) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      iVar10 = *(int *)(unaff_EBP + -0x10);
      goto LAB_00481663;
    }
LAB_00481733:
    cVar5 = '\x03';
  }
  else {
LAB_00481663:
    if ((*(uint *)(iVar10 + 0x28) >> 0xf & 1) == 0) {
      iVar2 = *(int *)(*(int *)(DAT_006e54dc + 0x14) + 0xc);
      iVar4 = *(int *)(*(int *)(iVar2 + (char)(*(int *)(*(int *)(iVar10 + 0x48) + 0xf8) >> 4) * 4) +
                      (char)(*(int *)(*(int *)(iVar10 + 0x48) + 0xf4) >> 4) * 4);
      iVar2 = *(int *)(*(int *)(iVar2 + (char)(piVar1[1] >> 4) * 4) + (char)(*piVar1 >> 4) * 4);
      *(int *)(unaff_EBP + 8) = iVar2;
      if ((((iVar4 != iVar2) || (cVar5 = (char)iVar2, (char)((uint)iVar2 >> 8) != cVar5)) ||
          (*(char *)(unaff_EBP + 10) != cVar5)) || (*(char *)(unaff_EBP + 0xb) != cVar5)) {
        cVar5 = '\x04';
        goto LAB_0048173a;
      }
    }
    DAT_006e4a80 = 0;
    cVar5 = (**(code **)(**(int **)(iVar10 + 0x4c) + 0x54))
                      (piVar1,(*(int **)(iVar10 + 0x4c))[0x44],0,0);
    if (cVar5 == '\0') {
      if (DAT_006e4a7c == 7) goto LAB_00481733;
      if (DAT_006e4a7c != 0xb) goto LAB_004816f5;
      if ((DAT_006e4a80 != 0) && (DAT_006e4a80 != *(int *)(iVar10 + 0x7c))) {
        *(undefined2 *)(iVar10 + 0x8c) = *(undefined2 *)(DAT_006e4a80 + 0xf0);
        cVar5 = ((*(short *)(*(int *)(DAT_006e4a80 + 0x118) + 0x12) != 2) - 1U & 4) + 1;
        goto LAB_0048173a;
      }
    }
    cVar5 = '\x06';
  }
LAB_0048173a:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return cVar5;
}

