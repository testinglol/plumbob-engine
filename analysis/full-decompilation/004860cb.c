
void FUN_004860cb(void)

{
  short sVar1;
  char cVar2;
  undefined1 uVar3;
  SHORT SVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int *extraout_ECX;
  undefined1 uVar8;
  int unaff_EBP;
  char *pcVar9;
  
  FUN_00634c24();
  iVar6 = *(int *)(unaff_EBP + 0x14);
  (**(code **)(*extraout_ECX + 0x1c))();
  if ((char)extraout_ECX[0x2b] != '\0') {
    *(undefined1 *)(extraout_ECX + 0x2b) = 0;
    FUN_00488018();
    (**(code **)(*extraout_ECX + 0x1c))
              (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
               *(undefined4 *)(unaff_EBP + 0x10));
  }
  GetKeyState(0x10);
  SVar4 = GetKeyState(0x11);
  *(bool *)(unaff_EBP + 0x17) = SVar4 < 0;
  uVar5 = FUN_00492b26();
  *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
  if ((*(char *)(unaff_EBP + 0x17) == '\0') ||
     ((extraout_ECX[0xd] != 4 && (extraout_ECX[0xd] != 3)))) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  *(undefined1 *)((int)extraout_ECX + 0x81) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x89) = 0;
  *(undefined1 *)(extraout_ECX + 0x22) = 0;
  *(char *)((int)extraout_ECX + 0x79) = cVar2;
  *(undefined1 *)(extraout_ECX + 0x1d) = 1;
  extraout_ECX[0x17] = (int)*(short *)(iVar6 + 0xe);
  extraout_ECX[0x18] = (int)*(short *)(iVar6 + 0xc);
  if ((*(char *)((int)extraout_ECX + 0x77) != '\0') && (cVar2 != '\0')) {
    if ((extraout_ECX[0xf] != 0) && (cVar2 = FUN_00432644(), cVar2 != '\0')) {
      (**(code **)(*(int *)extraout_ECX[0xf] + 0x50))();
    }
    goto LAB_00486408;
  }
  extraout_ECX[0x1f] = -1;
  *(undefined1 *)((int)extraout_ECX + 0x7b) = 1;
  if (extraout_ECX[0xf] == 0) {
    piVar7 = (int *)FUN_00492b10();
    *(int **)(unaff_EBP + 0x10) = piVar7;
    if (piVar7 == (int *)0x0) {
      if (*(int *)(unaff_EBP + -0x10) != 1) {
        *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar6 + 0xc);
        FUN_004a6a9d(unaff_EBP + -0x20,unaff_EBP + -0x14);
        uVar8 = (undefined1)(*(int *)(unaff_EBP + -0x1c) >> 4);
        *(undefined1 *)(unaff_EBP + 0x14) = uVar8;
        uVar3 = (undefined1)(*(int *)(unaff_EBP + -0x20) >> 4);
        *(undefined1 *)(unaff_EBP + 0x15) = uVar3;
        *(undefined1 *)(unaff_EBP + 0x16) = *(undefined1 *)(unaff_EBP + -0x10);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(undefined1 *)(unaff_EBP + 0x10) = uVar8;
        *(undefined1 *)(unaff_EBP + 0x11) = uVar3;
        *(undefined1 *)(unaff_EBP + 0x12) = *(undefined1 *)(unaff_EBP + -0x10);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_00434ffd();
        *(undefined1 **)(unaff_EBP + -0x18) = &stack0xffffffcc;
        cVar2 = FUN_00486420();
        if (cVar2 == '\0') {
          DAT_006e4a7c = 0x1f;
          FUN_004864ed(0x1f);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      }
      goto LAB_00486408;
    }
    cVar2 = (**(code **)(*piVar7 + 0x68))();
    if (cVar2 != '\0') {
      sVar1 = *(short *)(*(int *)(unaff_EBP + 0x10) + 0xf0);
      *(uint *)(unaff_EBP + 0x10) =
           CONCAT22((short)((uint)*(int *)(unaff_EBP + 0x10) >> 0x10),sVar1);
      if (sVar1 == 0) {
        FUN_00492c37();
      }
      else {
        FUN_0047bd91(unaff_EBP + 0xc,unaff_EBP + 8,-*(int *)(DAT_006e54d8 + 0x84) & 3);
        FUN_00486a93(*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 8),
                     *(undefined4 *)(unaff_EBP + 0xc));
        extraout_ECX[0x19] = extraout_ECX[0x17];
        extraout_ECX[0x1a] = extraout_ECX[0x18];
        if ((char)extraout_ECX[0x20] == '\0') {
          *(undefined1 *)((int)extraout_ECX + 0x89) = 1;
        }
        else {
          *(undefined1 *)((int)extraout_ECX + 0x89) = 0;
          *(undefined1 *)((int)extraout_ECX + 0x81) = 1;
        }
        extraout_ECX[0x1f] = -1;
        *(undefined1 *)(extraout_ECX + 0x26) = 0;
        *(undefined1 *)((int)extraout_ECX + 0x7b) = 1;
        *(undefined1 *)((int)extraout_ECX + 0x97) = 1;
        FUN_0057a7f7(s_UI_object_move_006c5e70);
        extraout_ECX[0x28] = -0x10;
        extraout_ECX[0x27] = -0x10;
        extraout_ECX[0x2a] = -0x10;
        extraout_ECX[0x29] = -0x10;
        *(undefined1 *)((int)extraout_ECX + 0x95) = 1;
        *(undefined1 *)((int)extraout_ECX + 0x96) = 1;
        FUN_00487ead();
      }
      extraout_ECX[0x21] = (int)*(short *)(unaff_EBP + 0x10);
      goto LAB_00486408;
    }
    if (DAT_006e4a7c == 0) goto LAB_00486408;
  }
  else {
    if (DAT_006e4a7c == 0) {
      pcVar9 = s_UI_object_move_place_006c5e8c;
    }
    else {
      pcVar9 = s_UI_error_006c5e80;
    }
    FUN_0057a7f7(pcVar9);
    if (*(int *)(extraout_ECX[0xf] + 0x1ac) == 0) goto LAB_00486408;
    cVar2 = FUN_00432644();
    if (((cVar2 != '\0') && (*(int *)(extraout_ECX[0xf] + 0x1ac) != 0)) &&
       (*(short *)(extraout_ECX[0xf] + 0x1b0) != 0)) {
      *(undefined1 *)((int)extraout_ECX + 0x81) = 1;
      goto LAB_00486408;
    }
    *(undefined1 *)((int)extraout_ECX + 0x81) = 1;
    if ((*(char *)((int)extraout_ECX + 0xad) != '\0') && (iVar6 = FUN_00492b26(), 1 < iVar6)) {
      DAT_006e4a7c = 0x1f;
    }
  }
  FUN_004864ed(DAT_006e4a7c);
LAB_00486408:
  FUN_00486e21();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

