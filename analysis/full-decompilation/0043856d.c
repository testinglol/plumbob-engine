
int FUN_0043856d(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  FUN_00634c24();
  FUN_004b4533(*(undefined4 *)(DAT_006e486c + 4));
  FUN_004b475c();
  if (*(int **)(unaff_EBP + 0x1c) != (int *)0x0) {
    iVar4 = **(int **)(unaff_EBP + 0x1c);
    if (iVar4 == 1) {
      *(undefined1 *)(unaff_EBP + -0x67) = 1;
    }
    else if (iVar4 == 2) {
      *(undefined1 *)(unaff_EBP + -0x66) = 1;
    }
  }
  iVar5 = 3;
  FUN_004b463f(3,1,1);
  iVar4 = *(int *)(DAT_006e54dc + 0x10);
  *(undefined1 *)(unaff_EBP + -0xe) = 0;
  *(char *)(unaff_EBP + -0x10) = (char)(iVar4 / 2);
  *(char *)(unaff_EBP + -0xf) = (char)(iVar4 / 2);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00434d3d(unaff_EBP + -0x28);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_EBP + -0x28);
  *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x24);
  iVar1 = FUN_004b46a0();
  iVar4 = *(int *)(iVar1 + 0x70);
  iVar3 = *(int *)(iVar1 + 0x68);
  *(int *)(unaff_EBP + -0x88) = (*(int *)(iVar1 + 0x74) - *(int *)(iVar1 + 0x6c)) / 2;
  iVar1 = *(int *)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x8c) = (iVar4 - iVar3) / 2;
  iVar4 = *(int *)(iVar1 + 0x60);
  if ((*(short *)(iVar4 + 0x14) == 0) || (*(short *)(iVar4 + 0x16) == -1)) {
    iVar4 = (*(short *)(iVar4 + 0x7a) + 4) % 8;
    *(int *)(unaff_EBP + -0x10) = iVar4;
    *(int *)(unaff_EBP + -0x80) = iVar4;
    if (*(int **)(unaff_EBP + 0x20) == (int *)0x0) {
      do {
        FUN_004b4bbd(iVar5);
        iVar3 = unaff_EBP + -0x9c;
        uVar8 = 0xffffffff;
        iVar4 = unaff_EBP + -0x28;
        uVar7 = 1;
        FUN_004b469d(iVar4,1,iVar3,0xffffffff);
        FUN_004b97eb(iVar4,uVar7,iVar3,uVar8);
        puVar2 = (undefined4 *)
                 FUN_00438834(unaff_EBP + -0xac,*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x9c,0,0
                              ,*(undefined4 *)(unaff_EBP + -0x10),iVar5,
                              *(undefined4 *)(unaff_EBP + 0xc),1,0,*(undefined4 *)(unaff_EBP + 0x1c)
                             );
        *(undefined4 *)(unaff_EBP + -0x20) = *puVar2;
        *(undefined4 *)(unaff_EBP + -0x1c) = puVar2[1];
        *(undefined4 *)(unaff_EBP + -0x18) = puVar2[2];
        *(undefined4 *)(unaff_EBP + -0x14) = puVar2[3];
        iVar3 = ((*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x18)) +
                *(int *)(unaff_EBP + 0x10)) / 2;
        iVar1 = iVar3 - *(int *)(unaff_EBP + -0x20);
        iVar4 = ((*(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x14)) +
                *(int *)(unaff_EBP + 0x14)) / 2;
        iVar6 = iVar4 - *(int *)(unaff_EBP + -0x1c);
        if ((2 < iVar3) && (2 < iVar4)) break;
        iVar5 = iVar5 + -1;
      } while (0 < iVar5);
      if (iVar5 < 1) {
        iVar5 = 1;
      }
    }
    else {
      iVar5 = **(int **)(unaff_EBP + 0x20);
      FUN_004b4bbd(iVar5);
      iVar3 = unaff_EBP + -0x9c;
      uVar8 = 0xffffffff;
      iVar4 = unaff_EBP + -0x28;
      uVar7 = 1;
      FUN_004b469d(iVar4,1,iVar3,0xffffffff);
      FUN_004b97eb(iVar4,uVar7,iVar3,uVar8);
      puVar2 = (undefined4 *)
               FUN_00438834(unaff_EBP + -0xac,iVar1,unaff_EBP + -0x9c,0,0,
                            *(undefined4 *)(unaff_EBP + -0x10),iVar5,
                            *(undefined4 *)(unaff_EBP + 0xc),1,0,*(undefined4 *)(unaff_EBP + 0x1c));
      *(undefined4 *)(unaff_EBP + -0x20) = *puVar2;
      *(undefined4 *)(unaff_EBP + -0x1c) = puVar2[1];
      *(undefined4 *)(unaff_EBP + -0x18) = puVar2[2];
      *(undefined4 *)(unaff_EBP + -0x14) = puVar2[3];
      iVar1 = ((*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x18)) +
              *(int *)(unaff_EBP + 0x10)) / 2 - *(int *)(unaff_EBP + -0x20);
      iVar6 = ((*(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x14)) +
              *(int *)(unaff_EBP + 0x14)) / 2 - *(int *)(unaff_EBP + -0x1c);
    }
    FUN_004b4bbd(iVar5);
    iVar3 = unaff_EBP + -0x9c;
    uVar8 = 0xffffffff;
    iVar4 = unaff_EBP + -0x28;
    uVar7 = 1;
    FUN_004b469d(iVar4,1,iVar3,0xffffffff);
    FUN_004b97eb(iVar4,uVar7,iVar3,uVar8);
    *(int *)(unaff_EBP + 0x10) = unaff_EBP + -0xac;
    if (*(int *)(unaff_EBP + 0x18) != 0) {
      *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x18);
    }
    puVar2 = (undefined4 *)
             FUN_00438834(unaff_EBP + -0xbc,*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x9c,iVar1,
                          iVar6,*(undefined4 *)(unaff_EBP + -0x10),iVar5,
                          *(undefined4 *)(unaff_EBP + 0xc),0,0,*(undefined4 *)(unaff_EBP + 0x1c));
    *(undefined4 *)(unaff_EBP + -0x20) = *puVar2;
    *(undefined4 *)(unaff_EBP + -0x1c) = puVar2[1];
    *(undefined4 *)(unaff_EBP + -0x18) = puVar2[2];
    *(undefined4 *)(unaff_EBP + -0x14) = puVar2[3];
    puVar2 = *(undefined4 **)(unaff_EBP + 0x10);
    *puVar2 = *(undefined4 *)(unaff_EBP + -0x20);
    puVar2[1] = *(undefined4 *)(unaff_EBP + -0x1c);
    puVar2[2] = *(undefined4 *)(unaff_EBP + -0x18);
    puVar2[3] = *(undefined4 *)(unaff_EBP + -0x14);
  }
  else {
    iVar5 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar5;
}

