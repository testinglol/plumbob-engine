
bool FUN_0045beca(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  uint uVar4;
  int unaff_EBP;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  FUN_00634c24();
  cVar1 = FUN_0045c02d(extraout_ECX);
  if (cVar1 == '\0') {
    iVar2 = FUN_0043acf5(0x7c4);
    if (iVar2 != 0) {
      uVar3 = FUN_00440b6d(iVar2);
      *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
      if ((short)uVar3 != 0) {
        uVar4 = (uint)*(short *)(unaff_EBP + -0x14);
        iVar2 = *(int *)(extraout_ECX + 0xdc);
        piVar5 = (int *)0x0;
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
        if ((0 < (int)uVar4) &&
           (uVar4 < (*(int *)(iVar2 + 0x1c) - *(int *)(iVar2 + 0x18) >> 2) + 1U)) {
          piVar5 = *(int **)(*(int *)(iVar2 + 0x18) + -4 + uVar4 * 4);
          *(int **)(unaff_EBP + -0x10) = piVar5;
        }
        (**(code **)(*piVar5 + 0x58))
                  (extraout_ECX + 0xf4,*(undefined4 *)(extraout_ECX + 0x110),0,0,1);
        FUN_0046de64();
        FUN_0046df0d(0);
        FUN_0046df0d(2);
        FUN_0046df0d(4);
        FUN_0046df0d(6);
        FUN_0046df27();
        FUN_0046df4f(0x10,0x50,0x10);
        FUN_0046df2c();
        FUN_0046dfa0(0,1);
        *(byte *)(unaff_EBP + -0x33) = *(byte *)(unaff_EBP + -0x33) & 0xdf;
        *(byte *)(unaff_EBP + -0x33) = *(byte *)(unaff_EBP + -0x33) | 0x20;
        uVar3 = *(undefined4 *)(unaff_EBP + 8);
        puVar6 = (undefined4 *)(unaff_EBP + -0x50);
        puVar7 = (undefined4 *)piVar5[0x4f];
        for (iVar2 = 0xf; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
        FUN_0041f010(extraout_ECX,*(undefined4 *)(unaff_EBP + -0x10),3,uVar3);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        cVar1 = FUN_0045d377(unaff_EBP + -0x94);
        bVar8 = cVar1 != '\0';
        if (!bVar8) {
          FUN_0044127f(*(undefined4 *)(unaff_EBP + -0x14));
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        goto LAB_0045c01d;
      }
    }
  }
  bVar8 = false;
LAB_0045c01d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar8;
}

