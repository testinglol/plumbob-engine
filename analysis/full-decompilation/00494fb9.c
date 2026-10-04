
void __fastcall FUN_00494fb9(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *local_c;
  int local_8;
  
  if ((char)param_1[0x3809] != '\0') {
    (**(code **)(*param_1 + 0x1c))();
  }
  (**(code **)(*param_1 + 4))();
  *(undefined1 *)(param_1 + 0x3809) = 0;
  param_1[0x380a] = 0;
  param_1[0x3816] = 0;
  param_1[0x3817] = 0;
  param_1[0x3814] = 0;
  cVar2 = *(char *)((int)param_1 + 0xe02e);
  if (cVar2 != '\0') {
    local_8 = 0;
    iVar3 = *(int *)(DAT_006e54d8 + 0x10);
    if (0 < iVar3) {
      local_c = param_1 + 9;
      do {
        iVar4 = 0;
        piVar5 = local_c;
        do {
          piVar6 = (int *)(*(int *)(*(int *)(*(int *)(cVar2 * 4 + 0x40 + DAT_006e54dc) + 0xc) +
                                   (char)local_8 * 4) + (char)iVar4 * 0xe);
          *piVar5 = *piVar6;
          piVar5[1] = piVar6[1];
          piVar1 = piVar5 + 3;
          piVar5[2] = piVar6[2];
          iVar4 = iVar4 + 1;
          piVar5 = (int *)((int)piVar5 + 0xe);
          *(short *)piVar1 = (short)piVar6[3];
        } while (iVar4 < iVar3);
        local_8 = local_8 + 1;
        local_c = local_c + 0xe0;
      } while (local_8 < iVar3);
    }
  }
  return;
}

