
void FUN_00615600(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  char *pcVar11;
  int iVar12;
  int iVar13;
  int in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  undefined4 in_stack_00000024;
  int *in_stack_0002711c;
  int in_stack_00027120;
  int in_stack_00027124;
  char *in_stack_00027128;
  
  FUN_00636080();
  iVar5 = *in_stack_0002711c;
  iVar1 = *(int *)(iVar5 + 0x10);
  iVar2 = *(int *)(iVar5 + 0x14);
  piVar10 = &stack0x00000018;
  if (((((-1 < in_stack_00027120) && (in_stack_00027120 <= iVar1)) && (-1 < in_stack_00027124)) &&
      (in_stack_00027124 <= iVar2)) &&
     (((iVar5 = *(int *)(iVar5 + 0x18) * in_stack_00027120,
       iVar5 = ((int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3) + in_stack_0002711c[2] * in_stack_00027124
       , pcVar11 = (char *)(iVar5 + in_stack_0002711c[1]),
       *(char *)(iVar5 + 2 + in_stack_0002711c[1]) != in_stack_00027128[2] ||
       (pcVar11[1] != in_stack_00027128[1])) || (*pcVar11 != *in_stack_00027128)))) {
    iVar5 = in_stack_00027124 + 1;
    if ((-1 < iVar5) && (iVar5 < iVar2)) {
      in_stack_00000024 = 1;
      piVar10 = (int *)&stack0x00000028;
      in_stack_00000018 = in_stack_00027124;
      in_stack_0000001c = in_stack_00027120;
      in_stack_00000020 = in_stack_00027120;
    }
    if (in_stack_00027124 < iVar2) {
      *piVar10 = iVar5;
      piVar10[1] = in_stack_00027120;
      piVar10[2] = in_stack_00027120;
      piVar10[3] = -1;
      piVar10 = piVar10 + 4;
    }
    while (&stack0x00000018 < piVar10) {
      iVar3 = piVar10[-1];
      iVar8 = piVar10[-3];
      iVar4 = piVar10[-2];
      piVar9 = piVar10 + -4;
      iVar13 = piVar10[-4] + iVar3;
      iVar5 = iVar8;
      if (iVar8 < 0) goto joined_r0x006158bf;
      do {
        iVar12 = in_stack_0002711c[2];
        iVar6 = FUN_00615330();
        if (iVar6 == 0) break;
        iVar6 = iVar5 * *(int *)(*in_stack_0002711c + 0x18);
        iVar5 = iVar5 + -1;
        *(undefined4 *)
         (((int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3) + in_stack_0002711c[1] + iVar12 * iVar13) =
             *(undefined4 *)in_stack_00027128;
      } while (-1 < iVar5);
      if (iVar8 <= iVar5) goto joined_r0x006158bf;
      iVar12 = iVar5 + 1;
      if ((((iVar12 < iVar8) && (piVar9 < &stack0x00027118)) && (-1 < iVar13 - iVar3)) &&
         (iVar13 - iVar3 < iVar2)) {
        *piVar9 = iVar13;
        piVar10[-3] = iVar12;
        piVar10[-2] = iVar8 + -1;
        piVar10[-1] = -iVar3;
        piVar9 = piVar10;
      }
      iVar5 = iVar8 + 1;
      piVar10 = piVar9;
joined_r0x006157c1:
      do {
        if (iVar5 < iVar1) {
          iVar8 = *in_stack_0002711c;
          iVar6 = in_stack_0002711c[2];
          iVar7 = FUN_00615330();
          if (iVar7 != 0) {
            iVar8 = iVar5 * *(int *)(iVar8 + 0x18);
            *(undefined4 *)
             (((int)(iVar8 + (iVar8 >> 0x1f & 7U)) >> 3) + in_stack_0002711c[1] + iVar6 * iVar13) =
                 *(undefined4 *)in_stack_00027128;
            iVar5 = iVar5 + 1;
            goto joined_r0x006157c1;
          }
        }
        if (((piVar10 < &stack0x00027118) && (-1 < iVar3 + iVar13)) && (iVar3 + iVar13 < iVar2)) {
          *piVar10 = iVar13;
          piVar10[1] = iVar12;
          piVar10[2] = iVar5 + -1;
          piVar10[3] = iVar3;
          piVar10 = piVar10 + 4;
        }
        piVar9 = piVar10;
        if (((iVar4 + 1 < iVar5) && (piVar10 < &stack0x00027118)) &&
           ((-1 < iVar13 - iVar3 && (iVar13 - iVar3 < iVar2)))) {
          *piVar10 = iVar13;
          piVar10[1] = iVar4 + 1;
          piVar10[2] = iVar5 + -1;
          piVar10[3] = -iVar3;
          piVar9 = piVar10 + 4;
        }
joined_r0x006158bf:
        do {
          piVar10 = piVar9;
          iVar5 = iVar5 + 1;
          if (iVar4 < iVar5) break;
          iVar8 = FUN_00615330();
          piVar9 = piVar10;
        } while (iVar8 == 0);
        iVar12 = iVar5;
      } while (iVar5 <= iVar4);
    }
  }
  return;
}

