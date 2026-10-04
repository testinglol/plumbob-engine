
void __thiscall FUN_0047cb76(int param_1,char *param_2,undefined1 *param_3)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  pcVar2 = param_2;
  iVar3 = FUN_0047d338();
  iVar1 = *(int *)(param_1 + 8);
  if (iVar3 != 0) {
    local_8 = 0;
    if (0 < iVar1) {
      do {
        param_2 = (char *)0x0;
        do {
          iVar4 = (int)*pcVar2 + (int)param_2;
          iVar5 = pcVar2[1] + local_8;
          if ((((-1 < iVar4) && (iVar4 < iVar1)) && (-1 < iVar5)) && (iVar5 < iVar1)) {
            if (((iVar4 == 0) || (iVar4 == iVar1 + -1)) || ((iVar5 == 0 || (iVar5 == iVar1 + -1))))
            {
              *(undefined1 *)
               (*(int *)(*(int *)(param_1 + 0xc) + (char)iVar4 * 4) + (int)(char)iVar5) = *param_3;
            }
            else {
              *(undefined1 *)
               (*(int *)(*(int *)(param_1 + 0xc) + (char)iVar4 * 4) + (int)(char)iVar5) =
                   *(undefined1 *)
                    (*(int *)(*(int *)(iVar3 + 0xc) + (char)param_2 * 4) + (int)(char)local_8);
            }
          }
          param_2 = (char *)((int)param_2 + 1);
        } while ((int)param_2 < iVar1);
        local_8 = local_8 + 1;
      } while (local_8 < iVar1);
    }
    local_8 = 0;
    if (0 < iVar1) {
      do {
        iVar4 = 0;
        do {
          if (((iVar4 - *pcVar2 < 0) || (iVar1 <= iVar4 - *pcVar2)) ||
             ((local_8 - pcVar2[1] < 0 || (iVar1 <= local_8 - pcVar2[1])))) {
            *(undefined1 *)
             (*(int *)(*(int *)(param_1 + 0xc) + (char)iVar4 * 4) + (int)(char)local_8) = *param_3;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar1);
        local_8 = local_8 + 1;
      } while (local_8 < iVar1);
    }
    FUN_00431242();
    FUN_006321f0(iVar3);
  }
  return;
}

