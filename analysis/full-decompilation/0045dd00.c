
undefined4 FUN_0045dd00(void)

{
  short *psVar1;
  short *psVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 uVar6;
  
  FUN_00634c24();
  uVar3 = FUN_0045d92c();
  psVar2 = *(short **)(unaff_EBP + 0xc);
  *(undefined1 *)(unaff_EBP + -0xd) = uVar3;
  if ((*psVar2 < 0) || ((short)(ushort)*(byte *)(*(int *)(unaff_EBP + 8) + 7) <= *psVar2)) {
    *(undefined4 *)(unaff_EBP + 8) = 8;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(unaff_EBP + 8,&DAT_00698f30);
  }
  iVar5 = FUN_004752f8();
  psVar1 = (short *)(iVar5 + *psVar2 * 2);
  if (*(char *)(unaff_EBP + -0xd) == '\0') {
    if (*psVar1 != 0) {
      uVar6 = 2;
      *psVar1 = *psVar1 + -1;
      goto LAB_0045dd6f;
    }
    *(byte *)((int)extraout_ECX + 0x5a) = *(byte *)((int)extraout_ECX + 0x5a) & 0xbf;
  }
  else {
    *(byte *)((int)extraout_ECX + 0x5a) = *(byte *)((int)extraout_ECX + 0x5a) | 0x40;
    if (psVar2[1] != 0) {
      uVar6 = 1;
      if ((extraout_ECX[0x291] != extraout_ECX[0x290]) &&
         ((*(int *)(*(int *)(unaff_EBP + 8) + 8) != 1 ||
          (((uint)extraout_ECX[(extraout_ECX[0x290] & 7U) * 0x11 + 0x218] >> 1 & 1) != 0)))) {
        FUN_0041ed45();
        *(undefined4 *)(unaff_EBP + -4) = 0;
        FUN_0045f8e7(unaff_EBP + -0x74);
        iVar5 = *(int *)(unaff_EBP + -0x6c);
        *(int *)(unaff_EBP + 0xc) = iVar5;
        if (iVar5 == 0) {
          uVar6 = 2;
        }
        else {
          FUN_00458419(extraout_ECX,iVar5,0);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_00458485(unaff_EBP + -0x74,0);
          if ((((*(uint *)(unaff_EBP + -0x34) >> 3 & 1) == 0) ||
              (*(short *)(unaff_EBP + -0x54) == 0)) ||
             (cVar4 = (**(code **)(*extraout_ECX + 0x34))
                                (*(undefined4 *)(unaff_EBP + 0xc),unaff_EBP + -0x60,
                                 *(undefined4 *)(unaff_EBP + -0x54),0), cVar4 == '\0')) {
            if (*(int *)(unaff_EBP + -0x6c) != 0) {
              FUN_00422d79(4,(short)extraout_ECX[0x3c],0);
            }
            uVar6 = 2;
          }
          else {
            FUN_0045e839(unaff_EBP + -0x74);
            iVar5 = *(int *)(unaff_EBP + 8);
            *psVar1 = 0;
            *(undefined4 *)(iVar5 + 8) = 1;
            iVar5 = FUN_004750a6();
            uVar6 = 3;
            *(undefined2 *)(iVar5 + 4) = *(undefined2 *)(*(int *)(unaff_EBP + 0xc) + 0xf0);
            *(byte *)((int)extraout_ECX + 0x5a) = *(byte *)((int)extraout_ECX + 0x5a) | 0x40;
          }
          *(undefined1 *)(unaff_EBP + -4) = 0;
          FUN_00458449();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
      }
      goto LAB_0045dd6f;
    }
  }
  uVar6 = 1;
LAB_0045dd6f:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

