
void __fastcall FUN_0046dd08(int param_1)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)**(int **)(param_1 + 0x1a4);
  if (piVar2 != *(int **)(param_1 + 0x1a4)) {
    do {
      if (piVar2[5] == 0) {
        if (piVar2[4] == 0) {
          if (*(int *)(DAT_006e486c + 0x24) != 0) {
            cVar1 = FUN_0042db93((int)piVar2 + 10,piVar2 + 3);
            goto LAB_0046dd65;
          }
        }
        else if ((piVar2[4] == 1) && (*(int *)(DAT_006e486c + 0x24) != 0)) {
          cVar1 = FUN_0042df00((int)piVar2 + 10,piVar2 + 3);
LAB_0046dd65:
          if (cVar1 == '\0') {
            piVar2[5] = 3;
          }
          else {
            *(undefined1 *)(*(int *)(DAT_006e486c + 0x1c) + 0xe0) = 1;
            piVar2[5] = 2;
          }
        }
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*(int *)(param_1 + 0x1a4));
  }
  FUN_0046dcc7();
  return;
}

