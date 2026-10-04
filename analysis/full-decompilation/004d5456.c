
void FUN_004d5456(void)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar7;
  undefined4 uVar8;
  
  FUN_00634c24();
  *(undefined2 *)(unaff_EBP + -0xe) = *(undefined2 *)(unaff_EBP + 8);
  piVar4 = *(int **)(extraout_ECX + 0x7c);
  *(undefined2 *)(unaff_EBP + -0x10) = *(undefined2 *)(unaff_EBP + 0xc);
  uVar3 = (**(code **)(*piVar4 + 0x38))();
  piVar4 = (int *)(**(code **)(**(int **)(extraout_ECX + 0x7c) + 4))
                            (unaff_EBP + -0x18,*(undefined4 *)(unaff_EBP + -0x10),1);
  *(char *)(unaff_EBP + 8) = (char)(piVar4[1] >> 4);
  *(char *)(unaff_EBP + 9) = (char)(*piVar4 >> 4);
  *(undefined1 *)(unaff_EBP + 10) = uVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004d5546(unaff_EBP + 8);
  iVar2 = DAT_006e54dc;
  if (*(char *)(unaff_EBP + 8) < '\x01') {
    *(undefined1 *)(unaff_EBP + 8) = 1;
  }
  else if (*(int *)(DAT_006e54dc + 0x10) + -2 < (int)*(char *)(unaff_EBP + 8)) {
    *(char *)(unaff_EBP + 8) = (char)*(int *)(DAT_006e54dc + 0x10) + -2;
  }
  if (*(char *)(unaff_EBP + 9) < '\x01') {
    *(undefined1 *)(unaff_EBP + 9) = 1;
  }
  else if (*(int *)(iVar2 + 0x10) + -2 < (int)*(char *)(unaff_EBP + 9)) {
    *(char *)(unaff_EBP + 9) = (char)*(int *)(iVar2 + 0x10) + -2;
  }
  uVar8 = 0;
  uVar7 = 1;
  cVar1 = *(char *)(DAT_006e54d8 + 0x78);
  *(char *)(unaff_EBP + 8) = *(char *)(unaff_EBP + 8) + *(char *)(DAT_006e54d8 + 0x70);
  piVar4 = *(int **)(extraout_ECX + 0x7c);
  *(char *)(unaff_EBP + 9) = *(char *)(unaff_EBP + 9) + cVar1;
  uVar5 = (**(code **)(*piVar4 + 0x38))(1,0);
  puVar6 = (undefined4 *)FUN_00434d3d(unaff_EBP + -0x20);
  FUN_004a7baa(*puVar6,puVar6[1],uVar5,uVar7,uVar8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

